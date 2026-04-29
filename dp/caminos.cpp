#include <iostream> 
#include <vector>

using namespace std;

vector<vector<long>> M;
vector<string> board;

long UNDEF = -1;

long paths(size_t x, size_t y) {
    if (x > M.size() - 1 || y > M.size() - 1) return 0; // me pase
    if (board[x][y] == '*') return 0; // si es invalido, no hay ningun camino.
    if (M.size() - 1 == x && M.size() - 1 == y) return 1; // estoy en el final y es valido

    if (M[x][y] == UNDEF) {
        // los caminos moviendome a la derecha o para arriba
        M[x][y] = paths(x + 1, y) + paths(x, y + 1);
    }

    return M[x][y];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    board.resize(n);
    for (int x = 0; x < n; x++) {
        string line; cin >> line;
        board[x] = line;
    }

    M.assign(n, vector<long>(n, UNDEF));

    cout << paths(0, 0) << "\n";
    return 0;
}


/*
....
.*..
.**.
....
*/