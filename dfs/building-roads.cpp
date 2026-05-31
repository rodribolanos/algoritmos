#include <iostream>
#include <vector>

using namespace std;


vector<vector<long>> G;

vector<bool> marcas;


bool dfs(long v) {
    // si esta marcado el vertice, retorno 
    if (marcas[v]) return false;

    marcas[v] = true;
    for (long neighbor : G[v]) {
        dfs(neighbor);
    }

    return true;
} 

int main() {
    long cities, roads;

    cin >> cities >> roads;
    // ponemos basura para no tener en cuenta el 0
    G.resize(cities + 1);
    marcas.resize(cities + 1, false);
    for (int i = 0; i < roads; i++) {
        long a, b;
        // tomo el road
        cin >> a >> b;
        // marco la doble relacion
        G[a].push_back(b);
        G[b].push_back(a);
    }

    long citie1 = -1;
    long citie2 = -1;

    vector<pair<long, long>> newRoads;
    for (int v = 1; v < marcas.size(); v++) {
        if (dfs(v)) {
            if (citie1 == -1) {
                // si no tenia primer ciudad, la marco con el primer vertice que encuentro
                citie1 = v;
            } else {
                citie2 = v;
                newRoads.push_back({citie1, citie2});
                citie1 = citie2;
            }
        }
    }

    cout << newRoads.size() << "\n";
    for (pair<long, long> road : newRoads) {
        cout << road.first << " " << road.second << "\n";
    }

    return 0;
}