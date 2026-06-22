#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/*
DJIKSTRA CON UN VECTORES, 
G[x] representa todas las relaciones del vertice x [{1, 4}, {2, 5}, {3, 10}]


Ir de x a 1, cuesta 10
*/

vector<vector<pair<long, long long>>> G; 

vector<long long> citiesCosts;
vector<bool> visited;

long long INF = 1e10;


using pll = pair<long long, long>;

int main() {
    long n, m;
    cin >> n >> m;

    citiesCosts.assign(n + 1, INF);

    G.assign(n + 1, vector<pair<long, long long>>());
    visited.assign(n + 1, false);
    /*
    PRIORITY QUEUE PARA DIJKSTRA. {10, 2} indica que cuesta 10 llegar al vertice 2 en la pq
    */
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    
    for (int i = 0; i < m; i++) {
        long a, b;
        long long c;

        cin >> a >> b >> c;
        G[a].push_back({b, c});
    }

    pq.push({0, 1});
    citiesCosts[1] = 0;
    visited[1] = true;

    while (!pq.empty()) {
        auto [cost, v] = pq.top();
        pq.pop();

        if (cost >= citiesCosts[v]) {
            continue;
        }
        
        citiesCosts[v] = cost;

        for (auto [w, vTowCost] : G[v]) {
            // es mejor viajar desde v a w costando weight que lo que ya descubri llegando a w por otro lado? 
            if (cost + vTowCost < citiesCosts[w]) {
                pq.push({cost + vTowCost, w});   
            }
        }
    }

    for (int r = 1; r < citiesCosts.size(); r++) {
        cout << citiesCosts[r] << " ";
    }

    return 0;
}