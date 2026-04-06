#include <iostream>
#include <vector> 

using namespace std; 

int calculatePeriodicStrings(string text) {
    // apenas empezamos, el mejor caso es que no puede ser reconstruido
    int length = text.size();
    int bestCase = length;

    for (int divs = 2; divs <= text.size(); divs++) {
    // El 1 es trivial
        // por cada divisor de bestCase
        if (length % divs == 0) {
            string pattern = text.substring(0, divs);
            
        }
    }

    // parto el string en n casos de divisores
    // me fijo si todos son patterns
    // si todos son patterns bestCase = min(bestCase, divisor)
}

int main() {
    int testCases;

    vector<int> results(testCases, 0);

    for (int i = 0; i < testCases; i++) { 
        string text;
        cin >> text;

        results[i] = calculatePeriodicStrings(text);
    }

    for (int r = 0; r < testCases; r++) {
        cout << results[r] << endl;
    }
    return 0;
}