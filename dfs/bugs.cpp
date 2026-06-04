#include <iostream>
#include <vector>

using namespace std;

vector<vector<long>> G;
vector<long> marcas;


/*
Si el v fue visitado, es decir, su marca es true, tiene que ser exactamente del mismo color que se le quiere marcar
Marcamos con 0 y 1 para poder facilitar cuentas.
*/
bool dfs(long v, long color) {
    if (marcas[v] != -1) {
        return marcas[v] == color;
    }

    marcas[v] = color;

    bool allHet = true;
    for (long neighbor : G[v]) {
        allHet = allHet && dfs(neighbor, 1 - color);
    }

    return allHet;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long scenarios; cin >> scenarios;

    for (int i = 1; i <= scenarios; i++) {
        long long kBugs, relations;
        cin >> kBugs >> relations;

        G.assign(kBugs + 1, vector<long>()); // vector para grafos
        marcas.assign(kBugs + 1, -1); //

        for (int r = 0; r < relations; r++) {
            long a, b;
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        bool allAreHetBugs = true;
        for (int v = 1; v < marcas.size(); v++) {
            if (marcas[v] == -1) {
                // si no esta marcado solo lo llamo
                allAreHetBugs = allAreHetBugs && dfs(v, 0);
            }
        }
        cout << "Scenario #" << i << ":" << "\n";
        if (!allAreHetBugs) {
            cout << "Suspicious bugs found!" << "\n";
        } else {
            cout << "No suspicious bugs found!" << "\n";
        }
    }

    return 0;
}