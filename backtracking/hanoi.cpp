#include <iostream>
#include <vector> 
using namespace std;

int MOVES = 0;
vector<pair<int,int>> fromTo;

void hanoi(int disks, int origin, int aux, int final) {
    if (disks == 0) return;

    // mover menos el mas grande a la auxiliar
    hanoi(disks - 1, origin, final, aux);
    // movemos a la destino el objetivo
    MOVES++;
    fromTo.push_back({origin, final});
    // volvemos a mover los que habiamos movido antes de la auxiliar al final
    hanoi(disks - 1, aux, origin, final);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;

    // 1, 2 y 3 representan las columnas. para este problema solo son ids.
    hanoi(n, 1, 2, 3);
    cout << MOVES << "\n";
    for (auto [from, to] : fromTo) { 
        cout << from << " " << to << "\n";
    }
}