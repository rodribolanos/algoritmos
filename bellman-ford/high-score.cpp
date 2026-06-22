#include <iostream> 
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using Graph = vector<vector<pll>>;
long long MINF = numeric_limits<ll>::min();

long n, m;

/*
Se tienen n habitaciones, m tuneles. Score inicial = 0. Cada tunel aumenta el score en X, cuando X puede ser negativo o positivo 

Si hay un ciclo positivo, imprimir -1 (si la ultima iteracion cambia)
*/


pair<vector<bool>, vector<long long>> distance_from(Graph& G, ll from) {
    // las distancias desde unoa todos es todo infinito
    vector<ll> dist(n + 1, MINF);

    vector<bool> changed(n + 1, false);
    dist[from] = 0; // la distnacia de 1 a 1 es 0.
    vector<ll> process = {from};
    for (auto z = 1; (z < G.size()) and (not process.empty()); z++) {
        // marco todos como que no cambiaron
        for(auto w : process) changed[w] = false;

        vector<ll> prev;
        swap(prev, process);

        for(auto v : prev) {
            for(auto [w, d] : G[v]) { // para todos los que tenia para procesar
                if(dist[w] < dist[v] + d) { // si la distancia que tenia a w, es peor (en este caso, menor, porque estoy maximizando) de lo que puedo hacer yendo de v a d, lo cambio
                    dist[w] = dist[v] + d; 
                    if(not changed[w]) process.push_back(w); // solo lo pusheo una vez a la cola
                    changed[w] = true; // marco que cambio 
                }
            }
        }
    }

    return {changed, dist};
}
int main() {
    cin >> n >> m;
    // vector que mantiene {vertice, peso}
    Graph Forward;
    Graph Backward;

    Forward.assign(n + 1, vector<pll>());
    Backward.assign(n+1, vector<pll>());

    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;

        Forward[a].push_back({b, c});
        Backward[b].push_back({a, c});
    }

    auto [changed_forward, dists_forward] = distance_from(Forward, 1);
    auto [changed_backward, dists_backward] = distance_from(Backward, n);

    for (auto v = 0; v < changed_forward.size(); v++) {
        // si el vertice v cambio en la ultima iteracion, y tiene distancia camino desde n hasta v en backward, significa que existe un camino de v hasta n
        if (changed_forward[v] && dists_backward[v] != MINF) {
            cout << "-1" << "\n";
            return 0;
        }
    }

    // si no hubo cambios significa que no hay un ciclo negativo hasta n 
    cout << dists_forward[n] << "\n";
    return 0;

}