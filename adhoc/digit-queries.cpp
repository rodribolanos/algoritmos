#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long q; 
    long long k;

    cin >> q;

    while (q--) {
        cin >> k;

        // 
        long long limite = 9;
        long long cifras = 1;
        long long cantNumeros = 9;
        while(k > limite) {
            k -= limite;
            // actualizo limite, 9 +
            cifras++;
            cantNumeros = cantNumeros * 10;
            // actualizo limite por la cantidad de numeros y cifras que tengo
            // 9 * 2 * 10, *3 * 10, etc
            limite = cantNumeros * cifras;
            
        }

        // en este caso k esta exactamente dentro del bloque que busco
        k--; // pasar a indice 0
        long numeroDesplazado = k / cifras; // es el numero exacto que quiero si k = 3, cifras = 3, quiero exactamente el primer numero
        // si k es 4 quiero el segundo (primero) indice 0
        long numero = (cantNumeros / 9) + numeroDesplazado;
        long indice = k % cifras; // el indice del numero que quiero
        
        string s = to_string(numero);
        cout << s[indice] << "\n";
    }
    return 0;
}