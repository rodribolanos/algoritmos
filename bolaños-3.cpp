#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<long>> matriz;

vector<vector<pair<bool, long>>> mem;

long m, n;
long long INF = 1e10;
long long NIL = -1;

/*
minSum de i j devuelve la minima suma desde la posicion i j hasta la posicion
m-1 n-1
*/
long long minSum(int i, int j) {
    if (i >= m || j >= n) return INF; // si me pase, no hay suma
    if (i == m - 1 && j == n - 1) return matriz[i][j]; // llegue al final    
    if (!mem[i][j].first) { // el primer elemento de la tupla indica si es valido
        long moveDiag = minSum(i + 1, j + 1);
        long moveRight = minSum(i + 1, j);
        long moveDown = minSum(i, j + 1); 
        mem[i][j] = {true, matriz[i][j] + min({moveDiag, moveRight, moveDown})};
    }

    return mem[i][j].second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long fila, columna; cin >> fila >> columna;
    m = fila;
    n = columna;
    
    mem.assign(fila + 1, vector<pair<bool, long>>(columna+1, {false, NIL}));
    matriz.assign(fila, vector<long>(columna));
    
    for (int f = 0; f < fila; f++) {
        for (int c = 0; c < columna; c++) {
            cin >> matriz[f][c];
        }
    }

    cout << minSum(0, 0) << "\n";
}