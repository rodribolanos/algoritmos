#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
// IDEA: Usar Z matching y buscar donde el indice del z y z[i] suma exactamente la longitud.

/*
Indice
palabra
z

0  1 2 3 4 5 6 7 8 9 10 11 
1  2 3 1 2 4 1 2 3 1 2  4
12 0 0 2 0 0 6 0 0 2 0  0

12           12     

REPETICION = 2 veces
Busco el primer indice del en el que la suma de i y z[i] da el length, para poder llenar el nuevo string a partir de ese z[i]
Ese i me da el primer periodo. En este caso 6. 
*/

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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;

    while (t--) {
        string s; cin >> s;

        vector<int> z = zarray(s);

        int size = s.size();
        // por default el minimo periodo es el string completo. no se repite
        int period = size;

        for (int i = 1; i < size; i++) {
            if (i + z[i] == size) {
                period = i; // encontramos el menor válido
                break;      // como vamos de menor a mayor, ya está
            }
        }
        // En este punto sabemos que periodo se repite.
        for(int l = 0; l < 8; l++) {
            cout << s[(size + l) % period];
        } 

        cout << "...\n";
    }
}