
#include <iostream>
#include <vector>
#include <tuple>
#include <numeric>

using namespace std;
using tint = long;

class UF {
    vector<tint> p;
    vector<tint> s;

public:
    UF(tint n) :
        p(n, 0),
        s(n, 1)
    {
        iota(p.begin(), p.end(), 0);
    }

    tint find(tint v) {
        return p[v] = (p[v] == v ? v : find(p[v]));
    }

    void unite(tint v, tint w) {
        auto rv = find(v), rw = find(w);
        if(rv == rw) return;
        if(s[rv] < s[rw]) swap(rv,rw);
        p[rw] = rv;
        s[rv] += s[rw];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    tint n, m;
    cin >> n >> m;

    vector<tuple<tint, tint, tint>> E(m);  //cost, v, w
    for(auto& [c,v,w] : E) cin >> v >> w >> c;
    sort(E.begin(), E.end());

    UF uf(n+1);
    tint res = 0, e = 0;
    for(auto [c, v, w] : E)
    if(uf.find(v) != uf.find(w)) {
        res += c;
        e += 1;
        uf.unite(v,w);
    }

    if(e < n-1) cout << "IMPOSSIBLE";
    else cout << res;
    cout << '\n';

    return 0;
}
