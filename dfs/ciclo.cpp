#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<long>> G;

// vector que representa si fue visitado (2), si esta siendo visitado (1) o si no fue visitado (0).
vector<long> visited;
vector<long> parents;

bool possible = false;
// IMPLEMENTACION PARA GRAFOS DIRIGIDOS, funciona para no dirigidos tambien, pero es mas compleja
vector<long> dfs(long v, long parent) {
    // si fue visitado, y fue visitado por otro padre, significa que hay un camino desde v a si mismo 
    
    if (visited[v] == 2) { return {}; } // si fue visitado, retorno
    
    if (visited[v] == 1) {
        
        long current = parent;
        vector<long> cicle; // armo un vector para el ciclo. voy pusheando todos sus padres hasta encontrarme con el nodo actual
        cicle.push_back(v);
        while (current != v) {
            cicle.push_back(current);
            current = parents[current];
        }
        cicle.push_back(v);
        if (cicle.size() > 2) {
            possible = true;
        }
        return cicle;
    }

    visited[v] = 1; // marco que esta siendo procesado
    parents[v] = parent; // marco quien es el padre

    for (long nb : G[v]) {
        // lanzo las marcas a los vecinos con v como padre, si es un digrafo comento el if, si es un grafo con doble relacion lo descomento para no llamar asi mismo
        // if (nb != parent) {
            vector<long> cicloDentro = dfs(nb, v);
            if (cicloDentro.size() > 0) {
                return cicloDentro;
            // }
        }
    }

    visited[v] = 2; // completo la visita
    return {};

}

int main() {
    long n, m;
    cin >> n >> m;
    G.assign(n + 1, vector<long>());
    visited.assign(n + 1, 0);
    parents.assign(n+1, -1);

    for (int r = 0; r < m; r++) {
        long a,b;
        cin >> a >> b;

        G[a].push_back(b);
        // G[b].push_back(a); // si comento esto es para un digrafo
    }

    for (int v = 1; v < visited.size(); v++) {
        if (visited[v] == 0) {
            vector<long> ciclo = dfs(v, v);
            if (ciclo.size() > 2) {
                cout << ciclo.size() << "\n";
                reverse(ciclo.begin(), ciclo.end());
                for (long city : ciclo) {
                    cout << city << " ";
                }
                break;
            }
        } 
    }

    if (!possible) {
        cout << "IMPOSSIBLE";
    }
}