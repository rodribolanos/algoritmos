#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// supone la posicion inicial, seguido de n (max 10) posiciones de beeps, finalizando con la posicion inicial
vector<pair<int, int>> world;
long INF = 1e7;
int beepers;

vector<vector<long>>> M;

// devuelve la distancia entre world[a] y world[b] sin tomar diagonales
long distance(int a, int b) {
    return abs(world[a].first - world[b].first) +
           abs(world[a].second - world[b].second);
}
/*
steps(lastIndex, accumulated) expresa la minima distancia para tomar la cantidad de beeps (beeps - accumulated.size()) desde la posicion world[lastIndex] hasta world.last() (inicio)
*/

/*
mask es bitmask tal que 110 representa la visita del beep 1 y 2
*/
long steps(int lastIndex, int mask) {
    if (mask == (1 << beepers) - 1) {
        // si ya visite todos los beepers, calculo la distancia desde el ultimo visitado a 0
        return distance(lastIndex, 0); // 
    }

    long ans = INF;
    if (M[lastIndex][mask] == NIL) {
        for (int i = 0; i < beepers; i++) {

            if (!(mask & (1 << i))) {
                int nextIndex = i + 1; // porque world[0] es inicio
                ans = min(ans,
                distance(lastIndex, nextIndex) +
                steps(nextIndex, mask | (1 << i))
            );           
         }
        }
    }
}
int main() {

    int t; cin >> t;

    while (t--) {
        int x; cin >> x;
        int y; cin >> y;

        world.clear();

        int startX; int startY; cin >> startX; cin >> startY;
        world.push_back{startX, startY};
        int beeps; cin >> beeps;

        for (int i = 0; i < beeps; i++) {
            cin >> x;
            cin >> y;
            
        }

        world.push_back{startX, startY}
        cout << steps(startX, startY, beeps) << "\n";
    }
}