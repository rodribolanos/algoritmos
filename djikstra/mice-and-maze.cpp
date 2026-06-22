#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


// G[a] = [{10, c}, {2, b}], indica que de a existe un camino a c de costo 10 y un camino de a a b de costo 2
vector<vector<pair<long, long>>> G;
vector<long> costs;

long INF = 1e9;

using pll = pair<long, long>;
/*
OBJETIVO: Ver que vertices llegan al vertice E gastando menos del tiempo T. Como las aristas son dirigidas, invierto el objetivo
se busca desde el vertice E hacia quienes llega gastando menos del tiempo T. 
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long testCases;
    cin >> testCases;
    while (testCases--) {
        long n, e, t, m;
        
        cin >> n >> e >> t >> m;
        
        // pq almacena paires de forma {costo, vertice}, ordenado por costo de menor a mayor
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        G.assign(n + 1, vector<pair<long, long>>());

        costs.assign(n + 1, INF);
        for (int i = 0; i < m; i++) {
            long a, b, c;
            cin >> a >> b >> c;
            G[b].push_back({c, a});
            // pusheo la relacion al reves
        }

        pq.push({0, e}); // llegar al vertice e cuesta 0

        while (!pq.empty()) {
            // mientras quedan vertices por averiguar
            auto [cost, v] = pq.top();
            pq.pop();

            // ESPECIFICO. si el costo de llegar hasta aca es mayor a v, ni lo reviso, porque es invalido.
            if (cost > t) {
                continue;
            }

            if (cost >= costs[v]) {
                // si el costo de llegar a v, es mayor al que tenia, corto
                continue; 
            }

            costs[v] = cost; //actualizo el costo

            for (auto [nbCost, nb] : G[v]) {
                // el nodo a procesar es mi vecino, costando lo que cuesto yo mas lo que cuesta el camino de llegar desde mi hasta el
                pq.push({nbCost + costs[v], nb});
            }
        }

        cout << count_if(costs.begin(), costs.end(), [t](long c) { return c <= t; }) << "\n";

        if (testCases != 0) {
            cout << "\n";
        }
    }
}