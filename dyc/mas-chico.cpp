#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long> numeros;


long indexMasChicoMayorOIgualA(long left, long right, long value) {
    // busco [L:R)
    while (left < right) {
        long mid = (right + left) / 2; // si no quiero que haya overflow hago left + (right - left) / 2

        // supongamos la lista [value, value, value], queremos el indice mas chico. si nuestro valor es mayor o igual, achicamos mid para la izquierda 
        if (numeros[mid] >= value) {
            right = mid;
        } else {
            // si el valor es menor, no nos interesa
            left = mid + 1;
        }
    }

    return left;

}
long indexMasGrandeMayorOIgualA(long left, long right, long value) {
    // busco [L:R)
    
    long l = left, r = right;
    while (l < r) {
        long mid = l + (r - l + 1) / 2;
        
        if (numeros[mid] > value) { // Buscamos el primero que NO cumple la condición
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    return l - 1;
}
int main() {
    long k;
    cin >> k;
    for (int i = 0; i < k; i++ ) {
        long a; cin >> a;
        numeros.push_back(a);
    }

    sort(numeros.begin(), numeros.end());
    
    long superior; cin >> superior;

    long left = 0; 
    long right = numeros.size();

    cout << indexMasGrandeMayorOIgualA(left, right, superior) << "\n";
    cout << indexMasChicoMayorOIgualA(left, right, superior) << "\n";
    return 0;
}