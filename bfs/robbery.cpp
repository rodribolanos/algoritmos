#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <deque>

using namespace std;



using ll = long long;

/*
Vectores para representar las direcciones. En cada posicion (x,y), se hace un for por dx y dy sumando (x+dx, y+dy) para generar las 4 direcciones posibles
*/
vector<ll> dx = {1, 0, -1, 0};
vector<ll> dy = {0, -1, 0, 1};

long INF = numeric_limits<ll>::max();
using Position = pair<ll, ll>;

/*
Vector para representar las posiciones "grabadas en un momento" x
sems[2] = {2, 3} indica que en el tiempo 2, la posicion 2,3 esta siendo grabada
*/
vector<Position> sems;

/*
 Vector que representa si para una posicion, el movimiento a la derecha, arriba, izquierda o abajo esta permitido

    permited[3][2][0] indica si el movimiento desde (3,2) a la derecha esta permitido
*/
vector<vector<vector<bool>>> permited;

vector<vector<ll>> costs;

/*
Devuelve la direccion al a que se movio (x1, y1) a (x2, y2)
0 si derecha
1 si arriba
2 si izquierda
3 si abajo
*/
ll resolveDirection(long x1, long y1, long x2, long y2) {
    if (x1 == x2) {
        return (y1 > y2) ? 1 : 3;
    } else {
        return (x1 > x2) ? 2 : 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll vr, hr;
    while (cin >> hr >> vr) {
        // cola con {costo, posicion}
        deque<pair<ll, Position>> positions;

        ll r; cin >> r;

        // en principio desde cualquier posicion horizontalxVertical, se pueden mover a los 4 lados
        permited.assign(hr, vector<vector<bool>>(vr, vector<bool>(4, true)));
        for (auto i = 0; i < r; i++) {
            long x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            long direct = resolveDirection(x1, y1, x2, y2);
            permited[x1][y1][direct]= false;
        }

        long m; cin >> m;
        sems.assign(501, {-1, -1});

        for (int s = 0; s < m; s++) {
            long t, x, y; cin >> t >> x >> y;
            sems[t] = {x , y};
        }

        positions.push_back({0, {0, 0}}); // pusheo el nodo inicial
        // asignar los costos de llegar a cada posicion
        costs.assign(hr, vector<ll>(vr, INF));


        while (not positions.empty() and costs[hr -1][vr - 1] == INF) {
            // mientras tenga posiciones para recorrer, las recorro
            ll x,y,time; Position position;
            tie(time, position) = positions.front();
            tie(x,y) = position;
            positions.pop_front();


            if (x < 0 or x >= hr or y < 0 or y >= vr) {
            // si el nodo era invalido, se iba del tablero, lo no proceso
                continue;
            }

            if (time <= 500 && sems[time] == position) {
                // si la posicion esta bloqueada, vuelve a la cola
                positions.push_back({time + 1, position});
                continue;
            } 
            
            if (costs[x][y] != INF) {
                continue;
            }

            // en este punto el costo es mejor
            costs[x][y] = time;

            for (int d = 0; d < 4; d++) {
                //recorrido por las 4 dirs
                long newX = x + dx[d];
                long newY = y + dy[d];
                long direction = resolveDirection(x, y, newX, newY);
                if (permited[x][y][direction]) {
                    positions.push_back({time + 1, {newX, newY}});
                }
            }
        }

        cout << costs[hr - 1][vr - 1] << "\n";
    }   
    return 0;
}