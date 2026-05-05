#include <iostream>
#include <vector>

using namespace std;

long NIL = -1;
long INF = 1e7;
long miles;
vector<vector<int>> mapa;
vector<vector<long>> M;

/*
minFuel es la minima cantidad de nafta que gasto en ir desde la posicion i h hasta la posicion (x/100, 0)
*/
long minFuel(long i, long h) {
    if (i == miles && h == 0) return 0; // llegar a la posicion final no cuesta nafta
    if (h < 0) return INF; // si baje de mas, es invalido
    if (h > 9) return INF; // si subi de mas
    if (i >= miles) return INF; // si me pase de milla tambien es invalido

    if (M[i][h] == NIL) {
        M[i][h] = min(
            60 - mapa[i][h] + minFuel(i + 1, h + 1), // subir uno en altura,
             min(
                30 - mapa[i][h] + minFuel(i + 1, h),
                20 - mapa[i][h] + minFuel(i + 1, h - 1)
             )
        );
    }

    return M[i][h];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t; cin >> t;

    while (t--) {
        long x; cin >> x;
        miles = x/100;

        M.assign(miles + 1, vector<long>(9 + 1, NIL));
        mapa.assign(miles + 1, vector<int>(10));
        // relleno el mapa
        for (int alt = 9; alt >= 0; alt--) {
            for (int p = 0; p < miles; p++) {
                cin >> mapa[p][alt];
            }
        }

        cout << minFuel(0, 0) << "\n";
        cout << "\n";
    }
    return 0;
}