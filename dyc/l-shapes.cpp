#include <iostream>
#include <vector>

using namespace std;


vector<vector<char>> matrix;


long posicionDeLAColocar(long fromX, long toX, long fromY, long toY, long x, long y, long mid) {
    if (fromX <= x && x < mid) {
        if (fromY <= y && y < mid) {
            // esta en el cuadrante izquierdo de X y superior de Y
            return 1;
        } else {
            // esta en el cuadrante izquierdo de X e inferior de Y
            return 4;
        }
    } else {
        // esta en cuadrante derecho de x
        if (fromY <= y && y < mid) {
            return 2;
            // esta en el cuadrante derecho de X y superior de Y
        } else {
            // esta en el cuadrante derecho de X, y inferior de Y
            return 3;
        }
    }
}
// tengo la matriz, y se donde exactamente esta el punto.
// divido la matriz en 4, de n/2 x n/2, como N es par, siempre quedara par. y pongo la L de manera que nunca toco el punto

// (x,y) representa la posicion exacta donde hay "un punto", o en este caso un espacio completo
void fill(long fromX, long toX, long fromY, long toY, long x, long y) {

    if (toX - fromX == 1 && toY - fromY == 1) return;
    // es lo mismo usar X que Y, porque es una matriz cuadrada
    long mid = (fromX + toX) / 2;
    
    long lPosition = posicionDeLAColocar(fromX, toX, fromY, toY, x, y, mid);

    if (lPosition == 1) {
        // no tengo que poner en la matriz superior izquierda
        fill(fromX, mid, fromY, mid, x, y);
        // matriz inferior izquierda, misma X, desplazo 1 hacia arriba
        matrix[mid - 1][mid] = 'A';
        fill(fromX, mid, mid, toY, mid - 1, mid);
        // matriz superior derecha, misma altura, voy 1 a la derecha 
        matrix[mid][mid - 1] = 'A'; 
        fill(mid, toX, fromY, mid, mid, mid - 1);
        // matriz inferior derecha, me muevo 1 a la derecha, y bajo 1
        matrix[mid][mid] = 'A';
        fill(mid, toX, mid, toY, mid, mid);

    } else if (lPosition == 2) {
        // no tengo que poner en la matriz superior derecha
        fill(mid, toX, mid, toY, x, y);
        // matriz superior izquierda, no me muevo
        matrix[mid - 1][mid - 1] = 'B';
        fill(fromX, mid, fromY, mid, mid - 1, mid - 1);
        // matriz inferior izquierda, mismo X, desplazo 1 hacia abajo
        matrix[mid - 1][mid] = 'B';
        fill(mid, toX, fromY, mid, mid, mid - 1);
        // matriz inferior derecha, desplazo en diagonal
        matrix[mid][mid] = 'B';
        fill(mid, toX, mid, toY, mid, mid);
    } else if (lPosition == 3) {
        // no tengo que poner . en la matriz inferior derecha
        fill(mid, toX, mid, toY, x, y);
        // matriz superior izquierda
        matrix[mid - 1][mid - 1] = 'C';
        fill(fromX, mid, fromY, mid, mid - 1, mid - 1);
        // matriz superior derecha, me muevo 1 en X 
        matrix[mid][mid - 1] = 'C';
        fill(mid, toX, fromY, mid, mid, mid - 1);
        // matriz inferior izquierda, me quedo en X, bajo en Y
        matrix[mid - 1][mid] = 'C';
        fill(mid, toX, mid, toY, mid - 1, mid);
    } else {
        // en este caso, el punto esta en en la matriz abajo a la izquierda
        fill(fromX, mid, mid, toY, x, y);
        // matriz superior izquierda
        matrix[mid - 1][mid - 1] = 'D';
        fill(fromX, mid, fromY, mid, mid - 1, mid - 1);
        // matriz superior derecha 
        matrix[mid][mid - 1] = 'D';
        fill(mid, toX, fromY, mid, mid, mid - 1);
        // matriz inferior derecha
        matrix[mid][mid] = 'D';
        fill(mid, toX, mid, toY, mid, mid);
    }
}


int main() {
    long n; cin >> n;

    long x, y; cin >> x >> y;
    matrix.resize(n+1, vector<char>(n+1));

    matrix[x][y] = '.';

    fill(1, n + 1, 1, n + 1, x, y);

    for(int f = 1; f < n + 1; f++) {
        for (int c = 1; c < n + 1; c++)
        cout << matrix[f][c];
    }
}