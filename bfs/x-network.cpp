#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


vector<vector<long>> G;
vector<bool> marks;
vector<long> parents;


/*
OBJETIVO: Encontrar los pasos intermedios minimos entre 2 vertices

Prereq: Siemrpe hay un camino desde init a dest

ESTRATEGIA: Armar un arbol BFS e ir construyendo la solucion en parents,
al final recorrer el vector de parents y no imprimir init y dest
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long t;
    cin >> t;

    queue<long> queue;

    while (t--) {
        long n;
        cin >> n;

        marks.assign(n, false);
        parents.assign(n, -1);
        G.assign(n, vector<long>());
        
        for (int i = 0; i < n; i++) {
            long a, k; cin >> a >> k;

            for (int r = 0; r < k; r++) {
                long b; cin >> b;
                G[a].push_back(b);
            }
            
        }

        long init, dest;
        cin >> init >> dest;

        queue.push(init);
        parents[init] = init;
        marks[init] = true;

        
        while (!queue.empty()) {
            long v = queue.front();
            queue.pop();

            for (long nb : G[v]) {
                if (!marks[nb]) {
                    queue.push(nb);
                    marks[nb] = true;
                    parents[nb] = v;
                }
            }
        }

        long cur = dest;
        vector<long> path;
        path.push_back(cur);

        while (cur != init) {
            cur = parents[cur];
            path.push_back(cur);
        }

        cout << init << " " << dest << " " << path.size() - 2 << "\n";
        if (t != 0) {
            cout << "\n";
        }
    }
    return 0;
}