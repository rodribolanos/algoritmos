#include <iostream>
#include <vector>
#include <tuple>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
using tint = long;

struct Edge { 
    tint source;
    tint dest;
    tint decibels;

    bool operator<(const Edge& other) const {
        return decibels < other.decibels;
    }

};


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

void bfs(const vector<vector<pair<tint, tint>>>& G, tint start, tint end) {
    // Si origen y destino son el mismo, el costo minimax es 0
    if (start == end) {
        cout << 0 << "\n";
        return;
    }

    // vector de visitados
    vector<bool> visited(G.size(), false);
    
    // guarda pares: {nodo_actual, max_peso_en_el_camino}
    queue<pair<tint, tint>> q;
    
    q.push({start, 0});
    visited[start] = true;

    while (!q.empty()) {
        auto [u, max_w] = q.front();
        q.pop();

        // Si llegamos al destino, imprimimos el máximo peso registrado en este camino
        if (u == end) {
            cout << max_w << "\n";
            return;
        }

        // Exploramos los vecinos de u
        for (auto edge : G[u]) {
            tint weight = edge.first;
            tint v = edge.second;

            if (!visited[v]) {
                visited[v] = true;
                // Al avanzar, el nuevo peso máximo es el máximo entre el camino que traíamos y la nueva arista
                q.push({v, max(max_w, weight)});
            }
        }
    }
}

int main() {
    tint c, s, q;
    tint testCase = 1;
    while (cin >> c >> s >> q && (c != 0 || s != 0 || q != 0)) {
        // grafo no dirigido que almacena lsita de adyacencias, con sus pesos {a, [{d, b}]} representa que c llega a b con el peso d 
        vector<Edge> edges;

        for (int i = 0; i < s; i++) {
            tint a, b, d;
            cin >> a >> b >> d;

            edges.push_back({a, b, d});
        }

        sort(edges.begin(), edges.end());
        UF uf(c + 1);
        vector<vector<pair<tint, tint>>> MST(c + 1);

        // encontrar el MST 
        for (Edge e: edges) {
            if (uf.find(e.source) != uf.find(e.dest)) {
                // si la arista no era de la misma cc, forma parte del camino minimax
                MST[e.source].push_back({e.decibels, e.dest});
                MST[e.dest].push_back({e.decibels, e.source});
                uf.unite(e.source, e.dest);
            }
        }

        if (testCase != 1) cout << "\n";
        cout << "Case #" << testCase << "\n";
        // G es el MST para ese grafo
        for (int querie = 0; querie < q; querie++) {
            tint q1, q2; cin >> q1 >> q2;
            if (uf.find(q1) != uf.find(q2)) {
                cout << "no path\n";
            } else {
                bfs(MST, q1, q2);
            }
        }
        
        testCase++;
    }

    return 0;
}