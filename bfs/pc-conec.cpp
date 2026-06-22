#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<long>> G;
vector<bool> marks;

vector<long> parents;
/*
OBJETIVO: Ver si hay un camino desde 1 hasta la pc n, si lo hay, imprimir el camino minimo.
Si no lo hay, imprimir "IMPOSSIBLE".

Estrategia: construir un arbol BFS desde la PC 1, pusheando sus vecinos.

Reconstruir la solucion mediante un vector que represente el arbol BFS

*/
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long n, m;
    cin >> n >> m;
    queue<long> queue;

    marks.assign(n + 1, false); // todos visitados en false
    G.assign(n + 1, vector<long>());
    parents.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        long a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    queue.push(1); // pusheo el vertice 1, que es la pc desde donde se quiere partir
    parents[1] = 1;
    marks[1] = true;
    while (!queue.empty()) {
        long v = queue.front();
        queue.pop(); // se hace pop para eliminar el vertice del principio
        
        if (v == n) {
            break;
            // si ya llegue a n corto
        }

        for (long nb : G[v]) {
            if (!marks[nb]) {
                queue.push(nb);
                marks[nb] = true;
                parents[nb] = v;
            }
        }
    }

    if (parents[n] == 0) {
        cout << "IMPOSSIBLE";
    } else {
        vector<long> path;
        long cur = n;            
        path.push_back(cur);
        while (cur != 1) {
            cur = parents[cur];
            path.push_back(cur);
        }
        reverse(path.begin(), path.end());
        cout << path.size() << "\n";

        for (long v : path) {
            cout << v << " ";
        }
    }

    return 0;
}