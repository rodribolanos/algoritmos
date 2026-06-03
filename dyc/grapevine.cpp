#include <iostream>

#include <vector>

using namespace std;

vector<vector<long>> field;

long best = 0;


long searchBestJ(long x, long left, long right, long lowerBound) {
    // busco [L, R], 
    if (left == right) {
        return left;
    }

    long mid = (left + right) / 2;
    if (field[x][mid] >= lowerBound) {
        // si es mayor, achicamos los de la derecha porque no sirven mas. mid queda igual porque es [L, mid)
        return searchBestJ(x, left, mid, lowerBound);
    } else {
        // Como no estrictamente menor al lowerBound, sabemos siempre que no es
        return searchBestJ(x, mid + 1, right, lowerBound);
    }
}

long searchBestK(long x, long left, long right, long l, long u, long n, long m) {
    // buscar el mejor (i, j) para esta fila, y de ahi buscar el maximo k con busqueda binaria
    // left <= j <= right

    if (field[x][right - 1] < l) {
        return best;  // si lo mas a la derecha de la fila supera a lo minimo, retorno lo que ya tengo
    }

    long j = searchBestJ(x, left, right, l);

    // en este momento j es mi j mas chico mayor o igual que 

    // teniendo eso, tengo que buscar el k

    long kLeft = 0; // minimo cuadrado valido
    long kRight = min(n - x, m - j); // maximo cuadrado valido

    if (kRight <= best) {
        // si lo maximo que puedo llegar, no es mejor a lo que tengo, retorno
        return best;
    }
    long kMid;
    while (kLeft < kRight) {
        kMid = (kRight + 1 + kLeft) / 2;
        if (field[x + kMid - 1][ j + kMid - 1] > u) {
            // si es mas grande, tengo que buscar para mas a la izquierda, entonces achico right
            kRight = kMid - 1;
        } else {
            // si es mas chico de lo que busco, achico la izquierda para buscar para la derecha
            kLeft = kMid;
        }
    }

    return max(best, kLeft);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long n, m;
    
    while (cin >> n >> m && n != 0 && m != 0) {
        //resize
        field.assign(n, vector<long>(m));

        // input
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                long p; cin >> p;
                field[x][y] = p;
            }
        }


        long intervalCases; cin >> intervalCases;

        for (int ic = 0; ic < intervalCases; ic++) {
            long u, l; cin >> l >> u;
            best = 0;
            for (int i = 0; i < n; i++) {
                best = searchBestK(i, 0, m, l, u, n, m);
            }

            cout << best << "\n";
        }

        cout << "-" << "\n";
        
    }
    return 0;
}