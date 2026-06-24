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
    tint t;
    cin >> t;
    while (t--) {
        tint computers; cin >> computers;
        tint successful = 0;
        tint unsuccessful = 0;
        UF uf(computers + 1);
        char type;
        // Intentamos leer el primer caracter de la siguiente consulta
        while (cin >> type) {
            
            // Si es 'c' o 'q', es una consulta válida de este caso
            if (type == 'c' || type == 'q') {
                tint u, v;
                cin >> u >> v; // Leemos los nodos
                
                if (type == 'c') {
                    // tengo que conectar
                    uf.unite(u, v);
                } else if (type == 'q') {
                    // Lógica de Find aquí
                    tint up = uf.find(u);
                    tint uv = uf.find(v);

                    if (up == uv) successful++; 
                    else unsuccessful++;
                }
            } 
            else {
                cin.putback(type); 
                
                break; 
            }
        }

        cout << successful << "," << unsuccessful << "\n";
        
        if (t > 0) cout << "\n";
    }

    return 0;
}
