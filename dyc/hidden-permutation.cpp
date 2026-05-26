#include <iostream>
#include <vector>

using namespace std;

/*
IDEA: Hacerlo estilo merge sort. Partir el arreglo en 2, en este caso indices 1 a k, k + 1 a n, asumiendo un arreglo de 1 a n.
Y luego ir comparandolos y ordenando
*/

vector<long> reorder(long l, long r, long n) {

    if (l + 1 == r) {
        cout << "? " << l << " " << r << "n";

        string ans; cin >> ans
    }
}

int main() {
    long n; cin >> n;
    
    vector<long> array(n);

    for (int i = 0; i < n; i ++) {
        array[i] = i + 1;
    }

    reorder(array);

}