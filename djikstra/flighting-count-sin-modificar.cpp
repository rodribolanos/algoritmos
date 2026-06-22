#include <iostream> 
#include <vector>
#include <queue>
#include <limits>
#include <tuple>

using namespace std;

using ll = long long;

ll INF = numeric_limits<ll>::max();


ll sirjala = 1;

//cada arista es peso + vecino
using digraph = vector<vector<pair<ll, ll>>>;

/*
DIJKSTRA CON PRIORITY QUEUE ALMACENANDO NEGATIVOS, PARA EVITAR USAR COMPARADOR. DIST[v] representa el negativo de la distancia de from a v
*/
vector<ll> dijkstra(const digraph& D, ll from) {
    vector<ll> dist(D.size(), INF);
    priority_queue<pair<ll, ll>> q;
    q.push({0, from});
    while(not q.empty()) {
        // sacar de la cola el front 
        auto [d, v] = q.top();
        q.pop();
        
        if(dist[v] != INF) continue;
        dist[v] = d;
        for(auto [dw, w] : D[v]) if(dist[w] == INF) {
            q.push({d - dw, w});
        }
    }
    return dist;
}

int main() {
    ll n, m;

    cin >> n >> m;
    
    
    auto G = digraph(2 * n + 1); 
    for (auto i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;

        G[a].push_back({c, b});
        G[a].push_back({c / 2, b + n});
        G[a + n].push_back({c, b + n});
    }

    cout << -dijkstra(G, sirjala)[2 * n] << "\n";

    return 0;
}