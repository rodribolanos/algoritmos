#include <iostream>
#include<vector>
#include <cmath>

using namespace std;

long NIL = -1;
long INF = 1e7;
vector<long> monedas;
vector<vector<pair<long, long>>> M;

/*
change de i k me cuanto es el minimo importe >= k, con las moendas de m[i] hasta m[0] utilizando la minima cantidad de monedas
*/
pair<long, long> change(long i, long k) {
    if (k <= 0) return {0, 0}; // si ya pague de mas    
    if (i <= 0) return {INF, INF}; // no tengo mas monedas

    if (M[i][k].first == NIL) {
        pair<long, long> noTomarMoneda = change(i-1, k);
        pair<long, long> tomarMoneda = change(i - 1, k - monedas[i - 1]);
        tomarMoneda.first += monedas[i-1]; // actualizo el importe
        tomarMoneda.second++; // actualizo que agarre una moneda
        M[i][k] = min(
            noTomarMoneda, // no agarrar la moneda actual
            tomarMoneda
        );
    }

    return M[i][k];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;

    while (t--) {
        long k; cin >> k;
        long n; cin >> n;
        // reasigno la memoria con la cantidad n + 1 de monedas (para acceder a n) y k+1 de importe para acceder a k
        M.assign(n + 1, vector<pair<long,long>>(k + 1, {NIL, NIL}));
        // reasigno tamanio de las monedas
        monedas.resize(n);
        // pido las monedas
        for (int i = 0; i < n; i++) {
            long m; cin >> m;
            monedas[i] = m;
        }

        pair<long, long> cambio = change(n, k);
        cout << cambio.first << " " << cambio.second << "\n";
    }
    return 0;
}