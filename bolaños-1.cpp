#include <iostream>
#include <vector>
#include <algorithm>

#ifndef SUBMIT
#include <cassert>
#endif

using namespace std;

// Construye el vector fail que representa las transiciones por fallo para p.
// Formalmente, fail[i+1] = tamaño del prefijo mas largo de p[:i-1] que matchea un sufijo de p[:i]
// fail[0] corresponde al string vacio y, como p[:-1] no existe, ponemos fail[0] = -1 para
// que todo cierre
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


int main() { 
    string word; cin >> word;

    
int main() {
    string s; cin >> s;
    int n = s.size();
    vector<int> phi = make_fail(s);
    int endSuffix = phi[n];

    if (n == 0) {
        cout << "0";
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
}