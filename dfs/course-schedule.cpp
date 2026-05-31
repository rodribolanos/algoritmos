#include <iostream>
#include <vector>

using namespace std;


/* 
vector de marcas con estados posibles:
0 -> no visitado, tengo que visitarlo
1 -> en proceso, estoy recorriendo su rama, si en algun momento me choco con algo en 1, es que hay un ciclo
2 -> terminado, alguien ya recorrio este vertice, tengo que terminar
*/
vector<long> marcas;

vector<vector<long>> G;

vector<long> toposort;

bool possible = true;

void dfs(long v) {
    // si esta marcado el vertice, retorno 
    if (marcas[v] == 2) return;

    if (marcas[v] == 1) {
        possible = false;
        return;
    }
    //empiezo a recorrer, lo marco como en proceso
    marcas[v] = 1;

    for (long neighbor : G[v]) {
        dfs(neighbor);
    }
    // termino de recorrer un vertice y sus aristas, lo marco como terminado
    marcas[v] = 2;
    // agrego el vertice al final, para tener todas sus dependencias antes
    toposort.push_back(v);
    
    return;
}

int main() {

    long n, m;

    cin >> n >> m;

    // marco n+1 vertices todos en 0, porque no estan visitados
    marcas.assign(n + 1, 0);
    G.resize(n + 1);
    for (int i = 0; i < m; i++) {
        long a, b;
        cin >> a >> b;

        G[a].push_back(b);
    }

    // por cada vertice hago el dfs
    for (int v = 1; v < marcas.size(); v++) {
            dfs(v);
    }

    if (possible) {
        for (int p = toposort.size(); p > 0; p--) {
            cout << toposort[p - 1] << " ";
        }
    } else {
        cout << "IMPOSSIBLE" << "\n";
    }

    return 0;
}