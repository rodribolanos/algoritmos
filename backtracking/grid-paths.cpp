#include <iostream>
#include <vector>

using namespace std;


/*
Tengo un vector de 7x7. Empiezo en el (0, 0). No me puedo mover para lados equivocados. 

*/

vector<vector<bool>> visited;

string path;

char dirs[] = {'L', 'R', 'D', 'U'};
long MOD = 1e9+7;

void redirect(char dir, int& x, int& y) {
    switch(dir) {
        case 'L':
            x--;
            break;
        case 'R':
            x++;
            break;
        case 'D':
            y++;
            break;
        case 'U':
            y--;
            break;
        default:
            break;
    }
}

void volveAtras(char dir, int& x, int& y) {
    switch(dir) {
        case 'L':
            x++;
            break;
        case 'R':
            x--;
            break;
        case 'D':
            y--;
            break;
        case 'U':
            y++;
            break;
        default:
            break;
    }
}

int cantPaths(int index = 0, int x = 0, int y = 0) {
    if (x == 6 && y == 0) return (index == 48); // llegue al final
    if (index == 48) return 0;
    if (0 > x || x > 6 || 0 > y || y > 6) return 0; // camino invalido, me sali del tablero
    if (visited[x][y]) return 0;
    

    visited[x][y] = true;

    char direccion = path[index];
    int sum = 0;
    for (char dir: dirs) {
        if (dir == direccion || direccion == '?') {
            redirect(dir, x, y);
            if (x >= 0 && x < 7 && y >= 0 && y < 7 && !visited[x][y]) {
                sum += cantPaths(index + 1, x, y);
            }
            volveAtras(dir, x, y);
        }
    }

    visited[x][y] = false;

    return sum;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string in;
    cin >> in;

    path = in;

    visited.assign(7, vector<bool>(7, false));
    visited[0][0] = true;
    cout << cantPaths() % MOD << "\n";
}