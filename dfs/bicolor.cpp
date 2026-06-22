#include <iostream>
#include <vector>

using namespace std;

vector<vector<long>> Graph;


/*
vector de colores para indicar si puede ser coloreado. -1 indica que no tiene color, 0 y 1 son los colores validos.
*/
vector<long> colors;

void dfs(long v, long color, bool& possible) {

    if (colors[v] != -1 && colors[v] != color) {
        // si esta coloreado y fue por otro color, no se puede bicolorear
        possible = false;
        return;
    }

    if (colors[v] != -1 && colors[v] == color) return;

    colors[v] = color;

    for (long nb : Graph[v]) {
        dfs(nb, 1 - color, possible);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    // n es la cantidad de vectores
    long n; 
    while (cin >> n && n != 0) {
        long r;
        // r es la cantidad de relaciones
        cin >> r;
        
        // resizes
        colors.assign(n + 1, -1);
        Graph.assign(n + 1, vector<long>());
        
        for (int i = 0; i < r; i++) {
            long a, b;
            cin >> a >> b;

            Graph[a].push_back(b);
            Graph[b].push_back(a);
        }

        bool possible = true;
        
        for (long v = 1; v < colors.size(); v++) {
            if (colors[v] == -1) {
                dfs(v, 0, possible);
            }
        }

        if (!possible) {
            cout << "NOT ";
        }

        cout << "BICOLORABLE." << "\n";

    }
    return 0;
}