#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct RaceCar {
    int number;
    int displacement;
};


int main() {
    int n;

    while (cin >> n && n != 0) {
        bool isPosible = true;
        vector<RaceCar> finishers(n);
        vector<int> starting_grid(n, -1);
        for (int i = 0; i < n; i++) {
            cin >> finishers[i].number >> finishers[i].displacement;
        }
        
        // al final del for index == n, por lo que recorri todo el vector de finishers
        for (int index = 0; index < n; index++) {
            int calculatedPosition = index + finishers[index].displacement; 
            if ( calculatedPosition < 0 || calculatedPosition >= n || starting_grid[calculatedPosition] != -1 ) {
                // si es distinto de -1 alguien ya se inscribio en esa celda, invalido
                // si es negativo o out of index, invalido
                cout << -1 << endl;
                isPosible = false;
                break;
            }

            starting_grid[calculatedPosition] = finishers[index].number;
        }

        if (isPosible) {
            for (int i = 0; i < n; i++) {
                cout << starting_grid[i] << (i == n - 1 ? "" : " ");
            }
            cout << endl;
        }
    }
    return 0;
}