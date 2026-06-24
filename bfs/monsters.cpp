#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;


/*
IDEAS: El grafo es "virtual", cada posicion se relaciona con sus lindantes. 

Manejar un vector de direcciones para el push de los vertices, hacer un for que es en todos los casos de 4 nodos.

Pushear siempre, revisar si es valido, e ir descubriendo todos los espacios desde una posicion i j

El juez tiene compilador 17 asiq se puede usar auto [] para el Pattern matching sobre una tupla

PROGRAMADOR: Rodrigo Bolanos
*/

using ll = long long;
using pll = pair<long, long>;
ll INF = numeric_limits<ll>::max();

// vector de direcciones. [ARRIBA, DERECHA, ABAJO, IZQUIERDA]
vector<pll> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

vector<vector<char>> grid;

vector<vector<ll>> monsters_dist;

ll n, m;

char resolveDirect(pll from, pll dest) {
    if (from.first == dest.first) {
        // tienen igual x
        if (from.second > dest.second) {
            return 'U';
        } else {
            return 'D';
        }
    } else {
        // tienen distinta x
        if (from.first > dest.first) {
            return 'L';
        } else {
            return 'R';
        }
    }
}
/*
q: representa una cola con los nodos iniciales, siendo que voy a insertar todos los monstruos desde afuera.
{dist, {x, y}} 

*/
void monstersBFS(queue<pair<ll, pll>> q) {

    while(not q.empty()) {
        auto [dist, pos] = q.front();
        q.pop();

        for (auto [dx, dy] : directions) {
            ll newX = pos.first + dx;
            ll newY = pos.second + dy;
            if (newX < 0 or newX >= m or newY < 0 or newY >= n) {
                // si la posicion esta fuera del mapa, ignoro
                continue;
            }

            if (grid[newX][newY] == '#') {
                // si es una trampa, ignoro
                continue;
            }

            if (monsters_dist[newX][newY] != INF) {
                // si ya estaba marcado, va a ser mejor. alguien llego antes
                continue;
            }
            monsters_dist[newX][newY] = dist + 1;
            // a los vecinos llego dando un paso
            q.push({ dist + 1 , {newX, newY}});
        }
    }
    
}  

vector<vector<pll>> parents;
vector<vector<ll>> personDists;

void personBFS(pll from) {
    parents.assign(m, vector<pll>(n));
    personDists.assign(m, vector<ll>(n, INF));
    queue<pair<ll, pll>> q;
    
    q.push({0, from});
    parents[from.first][from.second] = {-1, -1};
    personDists[from.first][from.second] = 0;
    
    while (not q.empty()) {
        auto [dist, position] = q.front();
        q.pop();

        for (auto [dx, dy] : directions) {
            ll newX = position.first + dx;
            ll newY = position.second + dy;
            if (newX < 0 or newX >= m or newY < 0 or newY >= n) {
                // si la posicion esta fuera del mapa, ignoro
                continue;
            }

            if (grid[newX][newY] == '#') {
                // si es una trampa, ignoro
                continue;
            }

            if (personDists[newX][newY] != INF or monsters_dist[newX][newY] <= dist + 1) {
                // si ya estaba marcado o el monstruo llega antes
                continue;
            }

            personDists[newX][newY] = dist + 1;
            parents[newX][newY] = position;
            // a los vecinos llego dando un paso
            q.push({ dist + 1 , {newX, newY}});
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;

    grid.assign(m, vector<char>(n));
    monsters_dist.assign(m, vector<ll>(n, INF));
    queue<pair<ll, pll>> monstersQueue;
    pll from;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            char a; cin >> a;
            grid[x][y] = a;

            if (a == 'M') {
                monsters_dist[x][y] = 0;
                monstersQueue.push({0, {x, y}});
            }

            if (a == 'A') {
                from = {x, y};
            }
        }
    }
    monstersBFS(monstersQueue);
    personBFS(from);
    vector<pll> outs;

    for (ll fx = 0; fx < m; fx++) {
        outs.emplace_back(fx, 0);
        outs.emplace_back(fx, n - 1);
    }

    for (ll fy = 0; fy < n; fy++) {
        outs.emplace_back(0, fy);
        outs.emplace_back(m - 1, fy);
    }

    pll exit = {-1, -1};

    for (pll out : outs) {
        // si habia alguna salida valida, la convierto en valida
        if (personDists[out.first][out.second] != INF) {
            exit = out;
            break;
        }
    }    

    if (exit.first != -1) {
        cout << "YES" << "\n";
        cout << personDists[exit.first][exit.second] << "\n";

        pll act = exit;
        vector<char> path;
        while (act != from) {
            char direct = resolveDirect(parents[act.first][act.second], act);
            path.push_back(direct);
            act = parents[act.first][act.second];
        }

        reverse(path.begin(), path.end());

        for (char c : path) {
            cout << c;
        }

        cout << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}