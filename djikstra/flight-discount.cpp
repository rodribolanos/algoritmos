#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

using costVertex = pair<long long, long>;
vector<vector<costVertex>> G; 

long long INF = LLONG_MAX;

vector<vector<long long>> costs;

long sirjala = 1;

/*
Encontrar el camino de minimo valor desde Syrjala (vertex 1) a Metsala (vertex N). Se puede aplicar un cupon de descuento

*/
int main() {
    long n, m;

    cin >> n >> m;
    
    costs.assign(n + 1, vector<long long>(2, INF));
    G.assign(n + 1, vector<costVertex>());

    // la tupla representa {costo, vertice, descuentoUsado}
    priority_queue<tuple<long long, long, long>, vector<tuple<long long, long, long>>, greater<tuple<long long, long, long>>> pq;
    for (int i = 0; i < m; i++) {
        long a, b;
        long long c;
        cin >> a >> b >> c;

        G[a].push_back({c, b});
    }

    pq.push({0, sirjala, 0}); // llegar a la Syrjala cuesta 0

    while (!pq.empty()) {
        auto [cost, v, discount] = pq.top();
        pq.pop();

        if (cost > costs[v][discount]) {
            // si el costo de llegar a v, es mayor al que tenia, corto
            continue; 
        }

        costs[v][discount] = cost;

        for (auto [nbCost, nb] : G[v]) {

            // no usar el descuento 
            if (cost + (nbCost) < costs[nb][discount]) {
                costs[nb][discount] = nbCost + cost;
                pq.push({nbCost + cost, nb, discount});
            }

            // si no habia usado el descuento, y el costo de viajar usandolo es mejor de lo que tenia
            if (!discount && cost + nbCost / 2 < costs[nb][1]) {
                costs[nb][1] = cost + nbCost / 2;
                pq.push({nbCost / 2 + cost, nb, 1});          
            }

        }
    } 

    cout << costs[n][1] << "\n";
}