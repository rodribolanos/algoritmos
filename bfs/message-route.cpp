#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

/*
ENUNCIADO: https://cses.fi/problemset/task/1667/

PROGRAMADOR: Rodrigo Bolanos

Solucion: Armar arbol BFS, verificar la distancia desde 1 a n, y recorrer el vector de padres de n hasta llegar a 1
*/

using ll = long;
using Graph = vector<vector<ll>>;
ll INF = numeric_limits<ll>::max();


// devuelve {distancias, padres}
pair<vector<ll>, vector<ll>> bfs(Graph g, ll source) {
    vector<ll> p(g.size());
    vector<ll> d(g.size(), INF);

    p[source] = -1; // el padre de 
    d[source] = 0;
    queue<pair<ll, ll>> q; // queue que pushea {distancia, nodo}
    q.push({0, source});

    while (not q.empty()) {
        auto [dist, vertex] = q.front();
        q.pop();

        for (ll nb : g[vertex] ) {
            if (d[nb] == INF) {
                ll newDist = dist + 1;// llegar al nuevo es la mia mas uno
                q.push({newDist, nb});
                d[nb] = newDist;
                p[nb] = vertex;
            }
        }
    }

    return {d, p};
}

int main() {
    ll n, m;
    cin >> n >> m;

    Graph g(n + 1);
    for (int i = 0; i < m; i ++) {
        ll a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    auto [distances, parents] = bfs(g, 1);

    if (distances[n] == INF) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << distances[n] + 1 << "\n";
        vector<ll> path;
        for (int v = n; v != -1; v = parents[v]) {
            path.push_back(v);
        }

        reverse(path.begin(), path.end());

        for (ll vertex : path) {
            cout << vertex << " ";
        }

        cout << "\n";
    }
    return 0;
}