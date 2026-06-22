#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<long>> G;

// vector que representa si fue visitado (2), si esta siendo visitado (1) o si no fue visitado (0).
vector<long> parents;
vector<long> colors;
bool possible = true;
// 
vector<long> dfs(long v, long color, long parent) {
    // si fue visitado, y fue visitado por otro padre, significa que hay un camino desde v a si mismo 
    
    if (colors[v] == color) { return {}; } // si tiene el mismo color que queria, retorno
    
    if (colors[v] != -1 && colors[v] != color) {
        possible = false;
    // si fue coloreado, y fue por un distinto color hay ciclo        
        long current = parent;
        vector<long> cicle; // armo un vector para el ciclo. voy pusheando todos sus padres hasta encontrarme con el nodo actual
        while (current != v) {
            cicle.push_back(current);
            current = parents[current];

        }
        cicle.push_back(current);
        return cicle;
    }

    colors[v] = color; // marco que esta siendo procesado
    parents[v] = parent; // marco quien es el padre

    for (long nb : G[v]) {
        vector<long> cicloDentro = dfs(nb, 1 - color, v);
        if (cicloDentro.size() > 0) {
            return cicloDentro;
        }
        
    }

    return {};

}

int main() {
    long n, m;
    cin >> n >> m;
    G.assign(n + 1, vector<long>());
    colors.assign(n + 1, -1);
    parents.assign(n+1, -1);

    for (int r = 0; r < m; r++) {
        long a,b;
        cin >> a >> b;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int v = 1; v < colors.size(); v++) {
        if (colors[v] == -1) {
            vector<long> ciclo = dfs(v, 0, v);
            if (ciclo.size() > 0) {
                reverse(ciclo.begin(), ciclo.end());
                cout << "NO " << ciclo.size() << "\n"; 
                for (long vector : ciclo) {
                    cout << vector << " ";
                }
                break;
            }
        } 
    }

    if (possible) {
        cout << "SI " << "\n";
        for (int i = 1; i < colors.size(); i++) {
            cout << colors[i] + 1 << " ";
        }
    }
}