#include <iostream>
#include <vector> 


using namespace std;

pair<int, int> initial;
pair<int, int> final;

vector<pair<int, int>> pieces;


bool canPlay(int last, pair<int,int> piece, int &nextLast) {
    if (piece.first == last) {
        nextLast = piece.second;
        return true;
    }
    if (piece.second == last) {
        nextLast = piece.first;
        return true;
    }
    return false;
}
/*
IDEA: Marcar con un vector de usados que elementos fueron incluidos en el camino
Con un vector de acumulados marcar cual fue el ultimo, que es el que tiene que ser comparado
Con cantidad de movimientos los movimientos faltantes


PRECONDICION: accumulated empieza en su primer indice con el inicio
*/
bool hasPath(vector<bool> used, int moves, int rightLastPlayed) {
    // si no tengo movimientos, me fijo si el ultimo q puse coincide
    if (moves == 0) {
        return rightLastPlayed == final.first;
    }

    // si quedan mas de 1 movimiento, tengo que recorrer todas las restantes
    for (int i = 0; i < used.size(); i++) {
        if (!used[i]) { // filtro los que puedo usar 
            int newRight;
            if (canPlay(rightLastPlayed, pieces[i], newRight)) { // si puede ser jugada, sigo arrastrando
                used[i] = true;
                if (hasPath(used, moves - 1, newRight)) return true; // si hay camino, retorno y corto
                used[i] = false;
            }
        }
    }
    
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    int m;

    while (cin >> n && n != 0) {
        cin >> m; 
        int i1; int i2; cin >> i1; cin >> i2;
        initial = {i1, i2};

        int f1; int f2; cin >> f1; cin >> f2;
        final = {f1, f2};
        vector<bool> usedPieces(m);
        pieces.resize(m);

        for (int p = 0; p < m; p++) {
            // lleno el vector de piezas, de 0 a m.
            pair<int, int> pic; 
            cin >> pic.first;
            cin >> pic.second;
            
            pieces[p] = pic;
            usedPieces[p] = false;
        }

        if (hasPath(usedPieces, n, initial.second)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}