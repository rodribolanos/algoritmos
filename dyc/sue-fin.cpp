#include <iostream>


using namespace std;

long uno = 1;

void search(long k, long startF, long endF, long startS, long endS) {
    long swedenScore, finlandScore;

    if (endS < startS) {
        cout << "F " << startF + k - 1 << "\n";
        cin >> finlandScore;
        cout << "! " << finlandScore;
        return; 
    }

    // si tire a la basura todo finlandia
    if (endF < startF) {
        cout << "S " << startS + k - 1 << "\n";
        cin >> swedenScore;
        cout << "! " << swedenScore;
        return; 
    }

    if (k == 1) {
        cout << "S " << startS << "\n";
        cin >> swedenScore;
        cout << "F " << startF << "\n";
        cin >> finlandScore;

        cout << "! " << max(swedenScore, finlandScore) << "\n";
        return;
    }

    // si tire a la basura todo suecia
    
    
    long midSweden = (startS + endS) / 2;
    long midFinland = (startF + endF) / 2;
    
    cout << "S " << midSweden << "\n";
    cin >> swedenScore;
    cout << "F " << midFinland << "\n";
    cin >> finlandScore;

    long restBetter = (midFinland - startF) + 1 + (midSweden - startS);
    if (swedenScore > finlandScore) {
        if (k > restBetter) {
            // si k es mayor, y suecia era mejor, tengo que tirar todos los de suecia que yo se que son mayores
            search(k - (midSweden - startS + 1), startF, endF, midSweden + 1, endS);
        } else {
            // si k <= a lo que yo se que son mejores que finland, tengo que tirar todo lo de la derecha de finland, incluido al que consulte
            search(k, startF, midFinland - 1, startS, endS);
        }
    } else {
        if (k > restBetter) {
            // si k es mayor, y finlandia era mejor, tengo que tirar todos los de finlandia que yo se que son mayores
            search(k - (midFinland - startF + 1), midFinland + 1, endF, startS, endS);
        } else {
            // si k >= a lo que yo se que son mejores que sweden, tengo que tirar todo lo de la derecha de sweden, incluido al que consulte
            search(k, startF, endF, startS, midSweden - 1);
        }
    }
}

int main() {
    long n, k;

    cin >> n >> k;

    search(k, 1, n, 1, n);
}