#include <iostream>
#include <vector>

using namespace std;

/*
Tablero de NxM posiciones
*/
vector<vector<int>> board;
size_t N;
size_t M;

void redirect(int lado, long& i, long& j) {
    if (lado == 0) {
        i++;
    } else if (lado == 1) {
        i--;
    } else if (lado == 2) {
        j++;
    } else {    
        j--;
    }
}

void undirect(int lado, long& i, long& j) {
    if (lado == 0) {
        i--;
    } else if (lado == 1) {
        i++;
    } else if (lado == 2) {
        j--;
    } else {
        j++;
    }
}
/*
paths es la cantidad maxima de caminos desde la posicion i,j hasta la posicion N, M
sin pasar por una misma celda, y con todas las celdas del camino conteniendo un 1
*/

long paths(long i, long j, vector<vector<int>>& visited) {
    if (i < 0 || i >= N || j < 0 ||j  >= M) return 0; // me pase

    if (board[i][j] == 0) return 0; // si es invalido, no hay ningun camino.

    if (visited[i][j]) return 0; // si ya lo visite, no puedo seguir revisando

    if (i == N - 1 && j == M - 1 ) return 1; // estoy en el final y es valido, se puede asumir que board[N][M] = 1

    visited[i][j] = true;
    long sum = 0;
    for (int lados = 0; lados < 4; lados++) {
        redirect(lados, i, j);
        if (i >= 0 && i < N && j >= 0 && j < M) {
            // solo llamo si es viable para podar rama innecesaria
            sum += paths(i, j, visited);
        }
        undirect(lados, i, j);
    }
    
    visited[i][j] = false;
    return sum;
}

int main() {
    cin >> N;
    cin >> M;

    board.assign(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    vector<vector<int>> visited;
    visited.assign(N, vector<int>(M, false));
    cout << paths(0, 0, visited) << "\n";
    return 0;

}