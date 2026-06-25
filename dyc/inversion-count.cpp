#include <iostream>
#include <vector>

using namespace std;

vector<long> listaaa;

// hago merge sort y cuento la cantidad de veces que reordeno. asumo que siempre la izquierda debe ser menor que la derecha
pair<vector<long>, long> countUnorganized(long left, long right) {
    // busqueda [L;R)
    vector<long> orderedArray;
    if (left == right -1) {
        // un solo elemento esta siempre ordenado
        orderedArray.push_back(listaaa[left]);
        return {orderedArray, 0};
    }

    long mid = (right + left) / 2;

    // ordeno la lista izquierda y cuento los desordenados
    pair<vector<long>, long> unorganizedLeft = countUnorganized(left, mid);
    
    // ordeno la lista derecha y cuento los desordenados
    pair<vector<long>, long> unorganizedRight = countUnorganized(mid, right);

    size_t l = 0, r = 0;
    vector<long> leftArray = unorganizedLeft.first; // array ordenado izquierdo
    vector<long> rightArray = unorganizedRight.first; // array ordenado derecho
    long changes = unorganizedLeft.second + unorganizedRight.second; // cantidad total de cambios

    while (l < leftArray.size() && r < rightArray.size()) {
    // hago el combine de merge sorte, contando cada vez que pusheo uno de r por sobre l
        if (leftArray[l] > rightArray[r]) {
            orderedArray.push_back(rightArray[r]);
            r++;
            // como el de la izquierda es mas grande que el de la derecha, y la izquierda esta ordenada, la cantidad de malos ordenadados por ese unico elemento
            // es todos los que me faltan procesar de la izquierda
            changes += leftArray.size() - l;
        } else {
            orderedArray.push_back(leftArray[l]);
            l++;
        }
    }

    if (l == leftArray.size()) {
        // meter todos los de r
        for (int i = 0; i < rightArray.size() - r; i++) {
            orderedArray.push_back(rightArray[i + r]);
        }
    } else {
        // meter todos los de l
        for (int t = 0; t < leftArray.size() - l; t++) {
            orderedArray.push_back(leftArray[t + l]);
        }
    }

    return {orderedArray, changes};

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long t; cin >> t;

    while (t--) {
        long k;
        cin >> k;

        listaaa.clear();

        for (int p = 0; p < k; p++) {
            long a; cin >> a;
            listaaa.push_back(a);
        }

        pair<vector<long>, long> number = countUnorganized(0, listaaa.size());

        cout << number.second << "\n";
    }
    return 0;
}