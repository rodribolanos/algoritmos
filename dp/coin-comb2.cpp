#include <iostream> 
#include <vector>

using namespace std;

vector<long> monedas;
vector<vector<long>> M;
long MOD = 1e9+7;
long NIL = -1;
/*
comb de i k es la cantidad de combinaciones sumatorias posibles para el valor k usando monedas desde m[0] hasta m[i-1]
*/
long comb(long i, long k) {
    if (k == 0) return 1; // descubri una combinacion que suma k
    if (k < 0) return 0; // me pase, esto no suma K
    if (i <= 0) return 0; // no tengo mas moendas :c

    if (M[i][k] == NIL) {
        // no tomar la moneda o tomar la moneda y dar la posibilidad de volver a tomarla
        M[i][k] = (comb(i - 1, k) + comb(i, k - monedas[i - 1])) % MOD;
    }

    return M[i][k];
}

int main() {
    long n; cin >> n;
    long x; cin >> x;

    monedas.resize(n);
    for (int i = 0; i < n; i++) cin >> monedas[i];
    M.assign(n + 1, vector<long>(x + 1, NIL));

    cout << comb(n, x) << "\n";
}