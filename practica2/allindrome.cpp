#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> zarray(const string& s) {
    vector<int> z(s.size(), 0);
    for(int l = 0, i = 1, r = 1; i < s.size(); ++i) {
        if((z[i] = min(z[i-l], r-i)) < r-i) continue;
        for(l = i; r < s.size() and s[r-l] == s[r]; ++r);
        z[i] = r-l;
        if(r == i) ++r;
    }
    return z;
}
/*
IDEA Alindromo: Si P es un alindromo, entonces podemos expresar P = Q + R, siendo Q y R palindromos.
Al invertir P, reverse(P) = reverse(R) + reverse(Q) = R + Q, porque R y Q son palindromos por hipotesis
Sin concatenamos dos veces reverse(P) + reverse(P) = reverse(R) + reverse(Q) + reverse(R) + reverse(Q) = R + Q + R + Q. encontramos de nuevo a Q + R
Si con z, nos encontramos a alguien que encuentre a la longitud exacta de P, podemos decir que es un alindromo
*/

/*
IDEA Palindromo: chequear si los reversos son iguales: 
*/

bool isAlindrome(const string& palabra) {
    string reverso = string(palabra.rbegin(), palabra.rend());
    vector<int> z = zarray(palabra + '$' + reverso + reverso);
    int tamanio = palabra.size();
    // chequear si hay cantidad exacta
    int k = count(z.begin() + tamanio + 2, z.end(), tamanio);

    return k > 0;
}

bool isPalindrome(const string& palabra) {
    string reverso = string(palabra.rbegin(), palabra.rend());
    return palabra == reverso;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;

    while(t--) {
        string palabra;
        cin >> palabra;
        
        string out;
        if (isPalindrome(palabra)) {
            out = "palindrome";
        }
        else if (isAlindrome(palabra)) {
            out = "alindrome";
        } else {
            out = "simple";
        }

        cout << out << "\n";
    }
}