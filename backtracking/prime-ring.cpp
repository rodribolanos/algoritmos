#include <iostream>
#include <vector> 

using namespace std;
/*
IDEA: Tengo una lista de numeros, tengo que en primera instancia agarrar uno mas, y ver si es posible la solucion.
En este caso no podria tomar el agarrar o no agarrar el numero, porque si tengo n numeros, los casos validos tambien tienen
n numeros
*/

vector<int> nums; 

bool isPrime(int n) {
    // O(n)
    if (n <= 1) return false;
    if (n <= 3) return true;

    // Eliminate even numbers and multiples of 3
    if (n % 2 == 0 || n % 3 == 0) return false;

    // Check divisors starting from 5, skipping multiples of 2 and 3
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

void primeRing(int size, vector<int> accumulate, int ind = 0) {
    if (accumulate.size() == size) {
        for (int num : accumulate) {
            cout << num << " " << "\n";
        }
        return;
    }

    // recorro solo la cantidad de caracteres restantes, si tengo 7 en size y 2 acumulados, solo puedo ver 5 opciones
    for (int i = 0; i < size - accumulate.size(); i++) {
        int actualNum = nums[ind];
        int nextNum = nums[ind + 1 % size]
        if (isPrime(nums[ind] + nums[ind + 1 % size])) {
            primeRing(size, accumulate.push_back)
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int cases = 0;
    while (cin >> n) {
        cases++;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

    }

}