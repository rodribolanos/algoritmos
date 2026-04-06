/**
 * Author: Francisco Soulignac
 * Time in CF: 93ms
 */

#include <iostream>
#include <vector>

#define SUBMIT

#ifndef SUBMIT
#include <cassert>
#include <unordered_set>
#endif

using namespace std;

//calcula el zarray z que en la posicion i contiene el tamaño del prefijo comun mas largo
//entre s y s[i:], excluyendo la posicion 0.
//El algoritmo funciona manteniendo la ventaja una ventana [l,r) y un indice i tal que:
//- l < i \leq r
//- todos los valores de z[:i] ya fueron calculados
//- r es el maximo tal que z[l] + l + 1= r para l > 0
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

    size_t t; cin >> t;
    while(t--) {
        string s; cin >> s;

        // El string buscado es de la forma a + b + c, donde:
        // - a es prefijo
        // - c es sufijo
        // - a es el reverso de c, y
        // - ab es prefijo o bc es sufijo.
        // - b es un palindromo
        // De todos estos strings, existe uno donde len(a) = len(c) es maximo posible
        // De no ser asi, podriamos agregar un caracter a y a c, sacando el primero y ultimo de b

        // Buscamos la longitud de a y c
        size_t l = 0, r = s.size() - 1;
        while(l < r and s[l] == s[r]) ++l, --r;

        // si es palindromo, nada para hacer
        if(l >= r) {
#ifndef SUBMIT
            assert(s == string(s.rbegin(), s.rend()));
#endif
            cout << s << '\n';
            continue;
        }

        // Si no buscamos el palindromo que sea prefijo usando z-matching
        auto X = string(s.rbegin()+l, s.rbegin()+r+1) + "$" + string(s.begin()+l, s.begin()+r+1);
        auto Y = string(s.begin()+l, s.begin()+r+1) + "$" + string(s.rbegin()+l, s.rbegin()+r+1);

        auto zX = zarray(X);
        auto zY = zarray(Y);

        size_t x = 1, y = 1;
        while(x < zX.size() and x + zX[x] < zX.size()) ++x;
        while(y < zY.size() and y + zY[y] < zY.size()) ++y;

        cout << s.substr(0, l) << (x < y ? X.substr(x) : Y.substr(y)) << s.substr(r+1) << '\n';

#ifndef SUBMIT
        unordered_set<string> naive_res{""};
        for(auto i = 0ul; i <= s.size(); ++i)
        for(auto j = i; j <= s.size(); ++j)
        {
            auto cand = s.substr(0, i) + s.substr(j);
            if(cand == string(cand.rbegin(), cand.rend())) {
                if(cand.size() > naive_res.begin()->size()) naive_res = {cand};
                else if(cand.size() == naive_res.begin()->size()) naive_res.insert(cand);
            }
        }
        assert(naive_res.count(s.substr(0, l) + (x < y ? X.substr(x) : Y.substr(y)) + s.substr(r+1)) > 0);
#endif
    }

}
