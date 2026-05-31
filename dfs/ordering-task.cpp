#include <iostream>
#include <vector>

using namespace std;


vector<vector<long>> G;

vector<bool> marcas;

vector<long> toposort;

void dfs(long v) {
    // si esta marcado el vertice, retorno 
    if (marcas[v]) return;

    marcas[v] = true;

    for (long neighbor : G[v]) {
        dfs(neighbor);
    }
    // agrego el vertice al final, para tener todas sus dependencias antes
    toposort.push_back(v);
    return;
} 


/*
    IDEA: Hacer un DFS que vaya generando una lista de todos los vertices ordenado por sus dependencias, luego el reves
    nos da la lsita sin dependencias.
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long n, m;
    // n es la cantidad de tareas, m la cantidad de relaciones
    while (cin >> n >> m && (n != 0 || m != 0)) {
        // resize de la lista de adyacencias, y del vector de marcas. siempre con n + 1 para no tener que usar el v = 0
        G.assign(n + 1, vector<long>());
        marcas.assign(n + 1, false);
        toposort.clear();

        // tomamos el input de las aristas, como es dirigido, solo pusheamos a -> b, no b -> a
        for (int i = 0; i < m; i++) {
            long a, b;
            cin >> a >> b;
            G[a].push_back(b);
        }
        
        // hago el dfs por todos los vertices, y voy generando toposort
        for (int v = 1; v < marcas.size(); v++) {
            dfs(v);
        }

        // inicio p en size para imprimir desde el reves
        for (int p = toposort.size(); p > 0; p--) {
            cout << toposort[p - 1] << " ";
        }

        cout << "\n";
    } 

    return 0;
}