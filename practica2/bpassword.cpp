#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> make_fail(const string& p)
{
    vector<int> fail(p.size()+1, -1);
    for(int i = 0; i < p.size(); ++i) {
        fail[i+1] = fail[i] + 1;
        while(fail[i+1] > 0 and p[i] != p[fail[i+1]-1]) {
            fail[i+1] = fail[fail[i+1] - 1] + 1;
        }
    }
    return fail;
}

/*
IDEA: Siendo un string s de tamanio n, quiero ver cuanto es el sufijo que mas coincide al final.
Si el final es 0, no se puede, en caso contrario, me salteo los primeros phi[n] elementos, y busco otro lugar donde coincida 
Buscar con kmp en el string las veces donde el el phi[i] = phi[n] y sean el mas grande dentro de phi

Ejemplos:
abcdabc

phi[n] = 3. Busco desde phi[3] a phi[n-3] para no chocarme nuevamente, si encuentro un 3, es lo que busco

La contrasenia es de forma = t + ... + t + ... + t
*/
int main() {
    string s; cin >> s;
    int n = s.size();

    vector<int> phi = make_fail(s);
    int endSuffix = phi[n];

    if (n == 0) {
        cout << "Just a legend";
        return 0;
    } else {
        // cuento apariciones de ese sufijo desde ... + t ..., sin tener en cuenta el principio y el final.
        int apps = count(phi.begin() + 1 + endSuffix, phi.end() - endSuffix, endSuffix);
        if (apps > 0) {
            cout << s.substr(0, endSuffix);
        } else {
            cout << "Just a legend";
        }
    }
}