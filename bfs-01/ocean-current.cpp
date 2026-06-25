#include <iostream>
#include <vector>
#include <deque>
#include <limits>

using namespace std;

/*
ENUNCIADO: https://ac.nowcoder.com/acm/problem/117187

Observaciones: El grafo es "virtual"
*/
using ll = long;

// NORTE (subir 1 en Y) - NOROESTE (subir en Y, subir en X) - OESTE
vector<pair<ll, ll>> dirs = {{0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}};

vector<vector<ll>> grid;
long INF = numeric_limits<ll>::max();
using Position = pair<ll, ll>;
ll rows, columns;

ll bfs(ll x1, ll y1, ll x2, ll y2) {
    deque<pair<ll, Position>> positions;

    vector<vector<ll>> dist(columns, vector<ll>(rows, INF));

    positions.push_back({0, {x1, y1}});
    dist[x1][y1] = 0;
     while (not positions.empty() and dist[x2][y2] == INF) {
            // mientras tenga posiciones para recorrer, las recorro
            ll x,y,time; Position position;
            tie(time, position) = positions.front();
            tie(x,y) = position;
            positions.pop_front();

            for (int d = 0; d < 8; d++) {
                auto [dx, dy] = dirs[d];
                //recorrido por las 8 dirs
                long newX = x + dx;
                long newY = y + dy;

                
                if (newX < 0 or newX >= columns or newY < 0 or newY >= rows) {
                // si el nodo era invalido, se iba del tablero, lo no proceso
                    continue;
                } 

                ll extraTime = (grid[x][y] == d) ? 0 : 1;
                ll nuevoCosto = time + extraTime;

                if (nuevoCosto < dist[newX][newY]) {
                    dist[newX][newY] = nuevoCosto; // Lo actualizo ahora
                    if (extraTime == 0) {
                        positions.push_front({nuevoCosto, {newX, newY}});
                    } else {
                        positions.push_back({nuevoCosto, {newX, newY}});
                    }
                }
            }
        }

        return dist[x2][y2];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> rows >> columns;
    grid.assign(columns, vector<ll>(rows));
    // el eje x -> - <= x <= columns. La cantidad de columnas totales es donde me puedo mover en x
    // idem para eje y
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < columns; x++) {
            char current; 
            cin >> current;
            // Restar '0' convierte el char '7' en el número 7
            grid[x][y] = current - '0';
        }
    }

    ll q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        x1--; y1--; x2--; y2--;
        cout << bfs(x1, y1, x2, y2) << "\n";
    }

    return 0;
}
