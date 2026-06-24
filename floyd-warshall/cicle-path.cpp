#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

// Usamos un valor grande que no cause overflow al sumar INF + INF.
// 1e18 es un buen estándar para long long.
const ll INF = 1e18; 

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    // uso matriz de adyacencia. todos arrancan en infinito
    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));

    // por cada nodo, la distancia de un mismo nodo a si mismo es 0
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    // se lee el grafo en si 
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        
        // nos quedamos con el minimo pro si hay mas de un camino desde un vertice a otro
        dist[u][v] = min(dist[u][v], w); 
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Si la distancia de un nodo a sí mismo se volvió menor a 0, 
    // significa que es parte de un ciclo negativo.
    bool has_negative_cycle = false;
    for (int i = 1; i <= n; i++) {
        if (dist[i][i] < 0) {
            has_negative_cycle = true;
            break;
        }
    }

    if (has_negative_cycle) {
        cout << "Se detecto un ciclo negativo en el grafo.\n";
    } else {
        // Imprimimos la matriz de distancias mínimas
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] == INF) {
                    cout << "INF ";
                } else {
                    cout << dist[i][j] << " ";
                }
            }
            cout << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}