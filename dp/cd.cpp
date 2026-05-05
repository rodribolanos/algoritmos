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

class CdSolver { 
    vector<vector<long>> M;
    vector<long> ls;

public: 
    CdSolver(const vector<long>& lengths, long time)
        :  ls(lengths),
        M(lengths.size() + 1, vector<long>(time + 1, NIL))
    {}

    long get_value(size_t i, long j) {
        if (j < 0) return NEG_INF;
        if (j == 0 or i == 0) return 0; 

        if (M[i][j] == NIL) {
            M[i][j] = max(get_value(i-1, j), 
                                ls[i-1] + get_value(i-1, j - ls[i - 1]));
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
        auto s = get_solution(i-1, j - ls[i - 1]);
        s.push_back(i-1);
        return s;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    size_t k, n;
    while (cin >> k && cin >> n) {
        vector<long> v(n);

        for (auto& i : v) cin >> i;

        auto solver = CdSolver(v, k);

        vector<size_t> sol = solver.get_solution(n, k);

        for (size_t s: sol) {
            cout << v[s] << " "; 
        }

        cout << "sum:" << solver.get_value(n, k) << "\n";
    }
}