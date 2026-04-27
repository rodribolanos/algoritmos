#include <iostream>
#include <vector> 
#include <list> 

using namespace std;

vector<int> nums; 
// solucion con funcion isPrime que tarda O(n)

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

void printVector(vector<int> vec) {
    for (int n : vec) {
        cout << n << " ";
    }
}

// solucion con tabla de primos, tarda O(n), pero consulta en O(1)
vector<bool> primes;
/* 
IDEA: Usar una lista de acumulados para ir acumulando el resultado parcial.
Un vector de booleanos de n posiciones para marcar en la solucion actual que numeros fueron usados
Si la solucion actual uso el 1, 2. used se veria F T T F F F
*/
/*
PRECONDICION: Llamar a la funcion con un accumulate[0] = 0, para que no influya en la suma y poder usar front()
used debe ser un vector de n + 1 booleanos todos que comiencen en false
*/
void primeRing(vector<int>& accumulate, vector<bool>& used) {
    vector<vector<int>> solve;
    if (accumulate.size() == used.size() - 1) {
        if (primes[accumulate.back() + accumulate[0]]) {    
            printVector(accumulate);
            cout << "\n";
        }
        return;
    }
    

    for (int i = 2; i < used.size(); i++) {
        if (!used[i] && primes[accumulate.back() + i]) {
            used[i] = true;
            accumulate.push_back(i);
            primeRing(accumulate, used);
            // tengo que volver a marcar used[i] en false para la proxima llamada
            used[i] = false;
            accumulate.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    int cases = 0;
    int MAX_SUMS = 32;
    primes.assign(MAX_SUMS, true);
    primes[0] = false;
    primes[1] = false;
    // completar tabla de primes
    for (int i = 2; i < MAX_SUMS; i++) {
        if (primes[i]) {
            for (int k = 2; k*i < MAX_SUMS; k++) {
                primes[k*i] = false;
            }
        }       
    }
    while (cin >> n) {
        cases++;
        // asigno todos en true para empezar
        vector<int> accumulated;
        vector<bool> used(n + 1, false);
        accumulated.push_back(1);
        used[1] = true;

        cout << "Case " << cases << ": \n";
        primeRing(accumulated, used);
    }
    return 0;
}