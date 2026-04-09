#include <iostream>
#include <vector>
#include <cmath>
using namespace std; 

// URL: https://onlinejudge.org/external/100/10038.pdf

bool esJolly(int n, const vector<int>& secuencia) {
if (n <= 0) return false;
    if (n == 1) return true;

    // Usamos n elementos para que los índices 1 a n-1 sean válidos
    vector<bool> diferenciasVistas(n, false);
    int conteoUnicos = 0;

    for (int i = 0; i < n - 1; i++) {
        int diff = abs(secuencia[i] - secuencia[i + 1]);

        // La diferencia debe estar entre 1 y n-1
        if (diff >= 1 && diff <= n - 1) {
            if (!diferenciasVistas[diff]) {
                diferenciasVistas[diff] = true;
                conteoUnicos++;
            }
        }
    }

    // Es Jolly si encontramos todas las diferencias posibles (n-1)
    return conteoUnicos == (n - 1);
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> secuencia(n);
        for (int i = 0; i < n; i++) {
            cin >> secuencia[i];
        }

        if (esJolly(n, secuencia)) {
            cout << "Jolly" << endl;
        } else {
            cout << "Not jolly" << endl;
        }
    }
    return 0;
}