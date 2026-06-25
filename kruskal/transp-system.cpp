#include <iostream>
#include <vector>
#include <tuple>
#include <numeric>
#include <cmath>
#include <algorithm>

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
    tint tc; cin >> tc;

    for (int t = 1; t <= tc; t++) {
        tint n, r;
        cin >> n >> r;
        // vector de ciudades que marca {c, {x, y}} representa a la ciudad c en la posicion x y
        vector<pair<long, pair<long, long>>> cities;
        
        //tomo las ciudades
        for (int c = 0; c < n; c++) {
            long x, y; cin >> x >> y;

            cities.push_back({c, {x, y}});
        }

        // vector de distances (lista de aristas) {d, {c1, c2}} representa que c1 y c2 estan a la distancia d
        vector<pair<double, pair<long, long>>> distances;


        // genero la lista de aristas
        for (auto [c1, pos1] : cities) {
            tint x1, y1;
            tie (x1, y1) = pos1;
            for (auto [c2, pos2] : cities) {
                tint x2, y2;
                tie (x2, y2) = pos2;
                // no calculo distancia a mi mismo
                if (x1 == x2 && y1 == y2) continue;

                double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
                distances.push_back({distance, {c1, c2}});
            }
        }

        sort(distances.begin(), distances.end());

        UF uf(n);

        long states = 1;
        double roads = 0;
        double railroads = 0;
        for (auto [dist, cs] : distances) {
            tint city1, city2;
            tie(city1, city2) = cs;
            // si son iguales, ya existia algo que las unia
            if (uf.find(city1) != uf.find(city2)) { 
                // no son iguales, las tengo que unir
                uf.unite(city1, city2);
                if (dist > r) {
                    railroads += dist;
                    states++;
                } else {
                    roads += dist;
                    
                }
            } 
        }
        
        cout << "Case #" << t << ": " << states << " " << round(roads) << " " << (long) round(railroads) << "\n";
    }
    return 0;
}