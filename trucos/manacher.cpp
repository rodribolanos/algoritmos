#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Retorna el vector P donde P[i] es el radio del palíndromo 
 * centrado en la posición i de la cadena transformada.
 */
vector<int> getManacherVector(string s) {
    // Transformación para centros uniformes: "aba" -> "^#a#b#a#$"
    string T = "^";
    for (char c : s) {
        T += "#" + string(1, c);
    }
    T += "#$";

    int n = T.length();
    vector<int> P(n, 0);
    int C = 0; // Centro del palíndromo más a la derecha
    int R = 0; // Borde derecho del palíndromo más a la derecha

    for (int i = 1; i < n - 1; i++) {
        int espejo = 2 * C - i;

        // Si estamos dentro del rango de R, inicializamos con el espejo
        if (i < R) {
            P[i] = min(R - i, P[espejo]);
        }

        // Intento de expansión lineal
        while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
            // i elemento actual, P[i] las coincidencias hasta ahora, en principio 0, si coincide ++, + 1 y - 1 para mirar al costado
            //reviso los costados y actualizo 1 si el movimiento fue igual
            // no se pasa los bordes porque inicalizamos con ^ 
            P[i]++;
        }

        // Si expandimos más allá de R, actualizamos C y R
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    return P; // Retornamos el vector de radios
}