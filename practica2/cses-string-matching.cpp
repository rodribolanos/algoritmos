/**
 * Author: Francisco Soulignac
 * Time in CSES: 30ms
 */

#include <iostream>
#include <vector>
#include <algorithm>

#define SUBMIT

#ifndef SUBMIT
#include <cassert>
#endif

using namespace std;

//calcula el zarray z que en la posicion i contiene el tamaño del prefijo comun mas largo
//entre s y s[i:], i.e., z[i] = lcp(s, s[i:])
//El algoritmo funciona manteniendo la ventaja una ventana [l,r) y un indice i tal que:
//- l < i \leq r
//- todos los valores de z[:i] ya fueron calculados
//- r es el maximo tal que z[l] + l + 1= r para l > 0 (para l = 0, usamos  r = 1)
vector<int> zarray(const string& s) {
    vector<int> z(s.size(),s.size());
    for(int l = 0, i = 1, r = 1; i < s.size(); ++i) {
        if((z[i] = min(z[i-l], r-i)) < r-i) continue;
        for(l = i; r < s.size() and s[r-l] == s[r]; ++r);
        z[i] = r-l;
        if(r == i) ++r;
    }
    return z;
}


int main() {
#ifndef SUBMIT
    if(not freopen("in", "r", stdin)) return 1;
    if(not freopen("out", "w", stdout)) return 1;
#endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string text, pattern;
    cin >> text >> pattern;

    auto z = zarray(pattern + ' ' + text);
#ifndef SUBMIT
    auto s = pattern + ' ' + text;
    for(auto i = 0ul; i < z.size(); ++i) {
        assert(s.substr(i, z[i]) == s.substr(0, z[i]));
        assert(i + z[i] == s.size() or s[i + z[i]] != s[z[i]]);
    }
#endif

    cout << count(z.begin(), z.end(), pattern.size()) << '\n';
}
