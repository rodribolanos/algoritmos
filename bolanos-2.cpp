#include <iostream>
#include <vector> 
#include <cassert>

using namespace std;
/*
    1. formula recursiva
    2. superposicion de subproblemas
    3. mem
    4. bottom up opcional
    5. reconstruir solucion >:D

    struct Solver con constructor
        constructor(n, k) // O(nk), carga la matriz
        valor(i, j) -> M[i][j]   O(1) acceso a matriz
        solucion(i, j) -> S  O(i)

*/

const long NEG_INF = -1e7;
int NIL = -1;

class Solver { 
    vector<vector<long>> M;
    vector<long> v;

public: 
    Solver(const vector<long>& vals, long k)
        :  v(vals),
        M(vals.size() + 1, vector<long>(k + 1, NIL))
    {}

    // es el maximo valor de compra sin pasarte de j
    long get_value(size_t i, long j) {
        if (j < 0) return NEG_INF; // me pase de importe a poder comprar 
        if (j == 0 or i == 0) return 0; // no tengo mas para comprar  

        if (M[i][j] == NIL) {
            M[i][j] = max(get_value(i-1, j), 
                                v[i-1] + get_value(i-1, j - v[i - 1]));
        }

        return M[i][j];
    }

    // solucion de vector de indices, si quisiesemos la solucion con los valores podria hacer push back de v[i-1]
    vector<size_t> get_solution(size_t i, long j) {
        assert (j >= 0); // solucion invalida rompe
        if (i == 0) return {}; // si no me quedan elementos no puedo agarrar nada

        // si mi solucion es igual a la de no agarrarlo, tomo no agarrarlo
        if (get_value(i, j) == get_value(i-1, j))
            return get_solution(i-1, j);
        // sino lo agarro
        auto s = get_solution(i-1, j - v[i - 1]);
        s.push_back(i-1);
        return s;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    size_t n; 
    long k;
    cin >> n >> k;

    vector<long> v(n);

    long sum = 0;
    for (int i = 0; i < n; i++) {
        long valor; cin >> valor;
        v[i] = valor;
        sum += valor;

    }

    auto solver = Solver(v, sum);

    long sol = solver.get_value(n, sum / 2);

    long my_desc = min(sol * 2, k * 2);
    long other_desc = min((sum - sol) * 2, k * 2);

    cout << (sum * 10) - my_desc - other_desc << "\n";

    vector<size_t> solution = solver.get_solution(n, sum / 2);

    cout << solution.size() << " ";
    for (size_t i: solution) {
        cout << v[i] << " ";
    }
    return 0;
}