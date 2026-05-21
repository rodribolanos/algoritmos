#include <iostream>
#include <vector> 
#include <list> 
#include <algorithm>
using namespace std;

vector<int> nums; 
// solucion con funcion isPrime que tarda O(n)

vector<bool> isPrime;
vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};
vector<int> numbers;

void printVector(vector<int> vec) {
    for (int n : vec) {
        cout << n << " ";
    }
}

vector<int> best;

bool allUsed(vector<bool>& used) {
    for (bool u : used) {
       if (!u) return false; 
    }
    return true;
}

vector<int> bestRing; 

/* 
IDEA: Usar una lista de acumulados para ir acumulando el resultado parcial.
Un vector de booleanos de n posiciones para marcar en la solucion actual que numeros fueron usados
Si la solucion actual uso el 1, 2. used se veria F T T F F F
*/

long notUsedAmmount(vector<bool>& used) {
    long sum = 0;
    for (bool u: used) {
        if (!u) {
            sum++;
        }
    }
    return sum;
}
void primeRing(vector<int>& accumulate, vector<bool>& used) {
    if (accumulate.size() != 0 && accumulate.size() > bestRing.size()) {
        if (isPrime[accumulate.front() + accumulate.back()]) {
            bestRing = accumulate;
        }
    }

    // poda por factibilidad
    // si el size del mejor es mayor al que yo puedo
    // con lo que tengo + lo que puedo usar
    if (bestRing.size() > accumulate.size() + notUsedAmmount(used)) {
       return; 
    }

    for (int i = 0; i < used.size(); i++) {
        if (!used[i] && (accumulate.size() == 0 || isPrime[accumulate.back() + numbers[i]])) {
            used[i] = true;
            accumulate.push_back(numbers[i]);
            primeRing(accumulate, used);
            // tengo que volver a marcar used[i] en false para la proxima llamada
            accumulate.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    isPrime.assign(200, false);
    // relleno la tabla de primos, por cada uno de los primos, marco que si es primo
    // otra opcion es usar un find de un n
    for (int p : primes) {
        isPrime[p] = true;
    }
    
    int n; cin >> n;
    numbers.assign(n, 0);
    // used y numbers son de misma longitud para no hacer un vector de muchos espacios sin necesidad
    for (auto& num: numbers) cin >> num;
    sort(numbers.begin(), numbers.end());
    vector<bool> used(n, false);    
    vector<int> acc = {};
    bestRing = {};

    primeRing(acc, used);

    cout << bestRing.size() << "\n";
    for (int n : bestRing) {
        cout << n << " ";
    }
    return 0;
}