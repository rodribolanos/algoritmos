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
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, from});
    while(not q.empty()) {
        // sacar de la cola el front 
        ll d, v;
        tie(d, v) = q.top();
        q.pop();
        
        if(dist[v] != INF) continue;
        dist[v] = d;
        for(auto dnb : D[v]) if(dist[dnb.second] == INF) {
            q.push({d + dnb.first, dnb.second});
        }
    }
    return dist;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, m;

    while (cin >> n >> m && n != 0 && n != 0) {
        auto G = digraph(n);
        auto invertedG = digraph(n);

        ll source, dest;
        cin >> source >> dest;

        for (auto i = 0; i < m; i++) {
            ll a, b, c;
            cin >> a >> b >> c;
            
            G[a].push_back({c, b}); // llegar desde a -> b, cuesta c
            invertedG[b].push_back({c, a}); // llegar desde b -> a. cuesta c
        }

        vector<ll> directGraphCosts = dijkstra(G, source);
        vector<ll> invertedGraphCosts = dijkstra(invertedG, dest);

        auto newGraph = digraph(n);

        for (auto x = 0ul; x < G.size(); x++) {
            // cout << "distancia de source: " << source << " a dest " << x << ": " << directGraphCosts[x] << "\n";
            for (auto costVertex : G[x]) {
                ll cost, vertex;
                tie(cost, vertex) = costVertex;
                if (directGraphCosts[dest] != directGraphCosts[x] + cost + invertedGraphCosts[vertex]) {
                    // si no pertenece a la solucion minima, lo agrego
                    newGraph[x].push_back({cost, vertex});
                }
            }
        }

        vector<ll> costsWithoutMinimum = dijkstra(newGraph, source);

        ll dist = costsWithoutMinimum[dest];
        if (dist == INF) {
            cout << "-1";
        } else {
            cout << dist;
        }

        cout << "\n";
    }
}