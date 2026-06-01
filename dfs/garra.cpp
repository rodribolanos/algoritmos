#include <iostream>
#include <vector>

using namespace std;

vector<vector<long>> G;
/*
vector para marcar si un vertice es nodo central de una garra (0), si es un vertice (1) o si no fue visitado (-1)
*/
vector<long> asignaciones; 


bool possible = true;

void dfs(long v, long id) {
    // si ya fue asignado con el rol correspondiente, anda bien
    if (asignaciones[v] == id) {
        return;
    }

    // si ya fue asignado por otro con otro rol
    if (asignaciones[v] != -1 && asignaciones[v] != id) {
        possible = false;
        return;
    }

    asignaciones[v] = id;

    for (long nb : G[v]) {
        dfs(nb, 1 - id);
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    long k;

    while (cin >> k && k !=0) {

        G.assign(k + 1, vector<long>());
        asignaciones.assign(k + 1, -1);
        long a, b;

        while (cin >> a >> b && a !=0 && b != 0 ) {
            G[a].push_back(b);
            G[b].push_back(a);
        }

        for (int v = 1; v < asignaciones.size(); v++) {
            dfs(v, 0);
        }

        if (possible) {
            cout << "YES";
        } else {
            cout << "NO";
        }

        cout << "\n";
    }

}