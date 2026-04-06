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

int count_matches(const string& t, const string& p)
{
    int res = 0;
    auto fail = make_fail(p);
    for(int i = 0, j = 0; i < t.size(); ) {
        // transicionar todos los goto
        while(j < p.size() and t[i] == p[j]) {++i; ++j;}
        res += j == p.size() ? 1 : 0;           //match?
        if(j == 0) ++i;                         //fallo primer caracter
        else j = fail[j];                       //fallo otro caracter
    }
    return res;
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

#ifndef SUBMIT
    // testear make_fail
    for(int i = 0; i < pattern.size(); ++i) {
        auto suffix = pattern.substr(0, fail[i+1]);
        assert(suffix == pattern.substr(i+1-fail[i+1], fail[i+1]));
        for(int j = fail[i+1]+1; j <= i; ++j) {
            assert(pattern.substr(0, j) != pattern.substr(i+1-j, j));
        }
    }
#endif

    cout << count_matches(text, pattern) << '\n';
}
