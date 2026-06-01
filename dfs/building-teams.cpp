#include <iostream>
#include <vector>

using namespace std;

// grafo de amistades 
vector<vector<long>> G;

// lista de vectores con sus salas. si el vector tiene sala -1, significa que no esta visitado. lo utilizamos como vector de marcas
vector<long> roomsAssigned;

bool possible = true;

// las habitaciones las voy a marcar con 0 y 1, y cuando imprimo le sumo 1 para cumplir con el enunciado
void dfs(long v, long room) {
    // si el vertice tiene habitacion asignada, y es distinta de la que se le tiene que asignar, retorno 
    if (roomsAssigned[v] != -1 && roomsAssigned[v] != room) {
        possible = false;
        return;
    }

    if (roomsAssigned[v] == room) {
        // si fue visitado correctamente, corta ahi. caso base
        return;
    }
    roomsAssigned[v] = room;

    for (long neighbor : G[v]) {
        dfs(neighbor, 1 - room);
    }
    
    return;
} 


int main() {
    long pupils, friendships;

    cin >> pupils >> friendships;

    // se asignan n + 1 vectores para no usar el 0
    roomsAssigned.assign(pupils + 1, -1);
    G.assign(pupils + 1, vector<long>());

    // relleno el grafo de relaciones
    for (int f = 0; f < friendships; f++) {
        long a, b;
        cin >> a >> b;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int v = 1; v < roomsAssigned.size(); v++) {
        // solo lo llamo si no fue visitado
        if (roomsAssigned[v] == -1) {    
        // siempre llamo con 0 (en realidad 1) por default
            dfs(v, 0);
        }
    }

    if (possible) {
        for (size_t r = 1; r < roomsAssigned.size(); r++) {
            cout << roomsAssigned[r] + 1 << " ";
        }
    } else {
        cout << "IMPOSSIBLE";
    }
    return 0;
}