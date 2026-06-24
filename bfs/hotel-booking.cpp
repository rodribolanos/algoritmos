#include <iostream>
#include <vector>
#include <limits>
#include <tuple>
#include <cmath>

using namespace std;

using ll = long long;
using digraph = vector<vector<pair<ll, ll>>>;
ll INF = numeric_limits<ll>::max();

/*
IMPLEMENTACION DE DIJKSTRA CON DIJKSTRA 0 - X, reemplazar 600 por X para modificaciones
*/
vector<ll> dijkstra(const digraph& D, ll from, ll x) {
    vector<ll> dist(D.size(), INF);
    // costs[x] representa todas las ciudades a las que llego en costo x
    vector<vector<ll>> costs(x + 1, vector<ll>());
    
    costs[0] = {from};

    for (auto possibleTime = 0ul; possibleTime < costs.size(); possibleTime++) {
        for (auto city : costs[possibleTime]) {

            // si ya habia encontrado tiempo para esta ciduad, no me interesa.
            if (dist[city] != INF) continue;

            dist[city] = possibleTime;

            for (auto costCity : D[city]) {
                ll cost, nb;
                tie(cost, nb) = costCity;

                ll newTime = possibleTime + cost;
                if ((newTime) > x) {
                    // si tardo mas de 1 dia, no es valido.
                    continue;
                }
                // la distancia es valida y es la mejor.
                costs[newTime].push_back(nb);
            }

        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll n;
    
    while (cin >> n, n) {
        vector<ll> hotels{1};
        ll hotelsAmmount; cin >> hotelsAmmount;
        for (auto h = 0; h < hotelsAmmount; h++) {
            ll hotel; cin >> hotel;

            hotels.push_back(hotel);
        }


        hotels.push_back(n);
        digraph G(n + 1);

        ll conex; cin >> conex;
        for (auto c = 0ul; c < conex; c++) {
            ll c1, c2, m;
            cin >> c1 >> c2 >> m;
            // si no es valido ni lo pusheo
            G[c1].push_back({m, c2});
            G[c2].push_back({m, c1});
        }

        digraph newGraph(n + 1);
        // reconstruyo el grafo con el source hasta el final

        // por cada hotel, tengo que armar sus relaciones entre hoteles
        for (auto hot : hotels) {
            // por cada hotel z, hago su distancia a los demas
            vector<ll> distsFromHot = dijkstra(G, hot, 600);
            // solo los uno con otros hoteles
            for (auto hot2 : hotels) {
                // obtengo el hotel del for
                // si la distancia desde el hotel z hasta el hotel u 
                if (distsFromHot[hot2] != INF) {
                    newGraph[hot].emplace_back(1, hot2);
                }
            }
        }

        // por cada hotel tengo que hacer su dijkstra y reconstruir un grafo solo con hoteles
        vector<ll> realDists = dijkstra(newGraph, 1, 101);
        
        // cout << "distance from hotel 1 to hotels: ";
        // for (auto d : realDists) {
        //     cout << d << " ";
        // }
        // cout << "\n";

        if (realDists[n] != INF) {
            cout << max(0ll, realDists[n] - 1) << "\n";
        } else {
            cout << "-1" << "\n";
        }

    }

    return 0;
}