#include <iostream> 
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

using ll = long long;

struct Edge {
    ll source; 
    ll dest;
    ll cost;
};

using pll = pair<ll, ll>;
using Edges = vector<Edge>;

long n, m;

/*
Se tienen n habitaciones, m tuneles. Score inicial = 0. Cada tunel aumenta el score en X, cuando X puede ser negativo o positivo 

Si hay un ciclo positivo, imprimir -1 (si la ultima iteracion cambia)
*/


void find_negative_cicle(Edges& edges) {
    // como solo busco ciclos, puedo poner a todos en 0
    vector<ll> dist(n + 1, 0);

    vector<ll> parents(n + 1, -1); 
    vector<bool> changed(n + 1, false);
    ll x = -1;
    for (auto z = 1; z < dist.size(); z++) {
        x = -1; // x indica si hubo un cambio. si en la ultima iteracion x = -1 -> significa que no hay ciclo negativo
        // hago n iteraciones de bellman ford
        for (Edge e : edges) {
            // si la distancia que yo conozco para llegar al destino es peor que lo que puedo conseguir, cambio
            if (dist[e.source] + e.cost < dist[e.dest]) {
                parents[e.dest] = e.source; // actualizo el padre
                dist[e.dest] = dist[e.source] + e.cost;
                x = e.dest; // marco que se actualizo el vertice destino
            }
        }
    }

    if (x == -1) {
        // no hubo ciclo negativo
        cout << "NO" << "\n";
    } else {
        // hubo ciclo negativo
        for (int i = 0; i < n; ++i)
            x = parents[x];

        vector<int> cycle;
        for (int v = x;; v = parents[v]) {
            // busco el ciclo, termina cuando llego a x
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        // se da vuelta para mostrar el verdadero ciclo de descubrimiento
        reverse(cycle.begin(), cycle.end());

        cout << "YES" << "\n";

        for (int v : cycle)
            cout << v << ' ';
        cout << "\n";
    }
}
int main() {
    cin >> n >> m;
    // vector que mantiene {vertice, peso}
    Edges edges;

    for (int i = 0; i < m; i++) {
        ll source, dest, cost;
        cin >> source >> dest >> cost;

        edges.push_back({source, dest, cost});
    }

    find_negative_cicle(edges);

    return 0;

}