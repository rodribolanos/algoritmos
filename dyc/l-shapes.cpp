#include <iostream>
#include <vector>

using namespace std;


vector<vector<char>> matrix;

char currentLetter = 'A';

long posicionDeLAColocar(long fromX, long toX, long fromY, long toY, long x, long y, long midX, long midY) {
    if (fromX <= x && x < midX) {
        if (fromY <= y && y < midY) {
            // esta en el cuadrante izquierdo de X y superior de Y
            return 1;
        } else {
            // esta en el cuadrante izquierdo de X e inferior de Y
            return 4;
        }
    } else {
        // esta en cuadrante derecho de x
        if (fromY <= y && y < midY) {
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
    // como es cuadrada puedo usar cualquiera de los dos
    if (toX - fromX == 1) return;

    long midX = (fromX + toX) / 2;
    
    long midY = (fromY + toY) / 2;
    long lPosition = posicionDeLAColocar(fromX, toX, fromY, toY, x, y, midX, midY);

    char myLetter = currentLetter;
    currentLetter++;
    if (currentLetter > 'Z') {
        currentLetter = 'A'; // Volvemos a empezar si nos pasamos de la Z
    
    }
    if (lPosition == 1) {
        // no tengo que poner en la matriz superior izquierda
        fill(fromX, midX, fromY, midY, x, y);
        
        // matriz inferior izquierda, misma X, desplazo 1 hacia arriba
        matrix[midX - 1][midY] = myLetter;
        fill(fromX, midX, midY, toY, midX - 1, midY);
        
        // matriz superior derecha, misma altura, voy 1 a la derecha 
        matrix[midX][midY - 1] = myLetter; 
        fill(midX, toX, fromY, midY, midX, midY - 1);
        
        // matriz inferior derecha, me muevo 1 a la derecha, y bajo 1
        matrix[midX][midY] = myLetter;
        fill(midX, toX, midY, toY, midX, midY);

    } else if (lPosition == 2) {
        // no tengo que poner en la matriz superior derecha
        fill(midX, toX, fromY, midY, x, y);
        
        // matriz superior izquierda, no me muevo
        matrix[midX - 1][midY - 1] = myLetter;
        fill(fromX, midX, fromY, midY, midX - 1, midY - 1);
        
        // matriz inferior izquierda, mismo X, desplazo 1 hacia abajo
        matrix[midX - 1][midY] = myLetter;
        fill(fromX, midX, midY, toY, midX - 1, midY);
        
        // matriz inferior derecha, desplazo en diagonal
        matrix[midX][midY] = myLetter;
        fill(midX, toX, midY, toY, midX, midY);

    } else if (lPosition == 3) {
        // no tengo que poner . en la matriz inferior derecha
        fill(midX, toX, midY, toY, x, y);
        
        // matriz superior izquierda
        matrix[midX - 1][midY - 1] = myLetter;
        fill(fromX, midX, fromY, midY, midX - 1, midY - 1);
        
        // matriz superior derecha, me muevo 1 en X 
        matrix[midX][midY - 1] = myLetter;
        fill(midX, toX, fromY, midY, midX, midY - 1);
        
        // matriz inferior izquierda, me quedo en X, bajo en Y
        matrix[midX - 1][midY] = myLetter;
        fill(fromX, midX, midY, toY, midX - 1, midY);
    } else {
        // en este caso, el punto esta en en la matriz abajo a la izquierda
        fill(fromX, midX, midY, toY, x, y);
        
        // matriz superior izquierda
        matrix[midX - 1][midY - 1] = myLetter;
        fill(fromX, midX, fromY, midY, midX - 1, midY - 1);
        
        // matriz superior derecha 
        matrix[midX][midY - 1] = myLetter;
        fill(midX, toX, fromY, midY, midX, midY - 1);
        
        // matriz inferior derecha
        matrix[midX][midY] = myLetter;
        fill(midX, toX, midY, toY, midX, midY);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    long n; cin >> n;

    long x, y; cin >> x >> y;

    matrix.resize(n+1, vector<char>(n+1));

    matrix[x][y] = '.';
    fill(1, n + 1, 1, n + 1, x, y);

    for(int f = 1; f <= n; f++) {
        for (int c = 1; c <= n; c++) {
            cout << matrix[f][c];
        }
        cout << "\n";
    }

    return 0;
}