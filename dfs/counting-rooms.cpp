#include <iostream>
#include <vector>

using namespace std;

long n, m;

vector<char> flattenMatrix;

// matriz de visitados. los # los voy a tomar como visitados para retornar rapidamente y no tener que hacer un if extra
vector<char> visited;

string bestPath;

bool dfs(long vId) {
    
    if (vId < 0 || vId > n * m) {
        // si el id es invalido retorno
        return false;
    }

    if (visited[vId]) {
        return false;
    }

    visited[vId] = true; 
    // hago las cuatro llamadas dfs
    dfs(vId - m); // arriba
    if (vId % m != 0) {
        dfs(vId + 1); // solo si me puedo mover, es decir, no estoy en la ultima columna
    }
    if (vId % m != 1) {
        dfs(vId - 1); // izquierda, solo si no estoy en la columna de mas a la izquierda
    }
    dfs(vId + m); // abajo

    return true;
}
int main() {
    cin >> n >> m;

    // armo la matriz aplanada
    flattenMatrix.resize(n*m + 1);
    visited.assign(n * m + 1, true);
    for (int i = 1; i <= n * m; i++) {
        char piece; cin >> piece;

        flattenMatrix[i] = piece;
        
        if (piece == '.') {
            visited[i] = false;
        }
    }

    long rooms = 0;

    for (int v = 1; v < visited.size(); v++) {
        if (dfs(v)) {
            rooms++;
        }
    }

    cout << rooms;

}