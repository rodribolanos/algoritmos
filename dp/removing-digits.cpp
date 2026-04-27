#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long INF = 1e7;
const long UNDEF = -1;

vector<long> M;

long steps(long n) {
    if (n == 0) return 0; // llegue
    if (n < 10) return 1; // me queda un paso

    long res = INF;
    long aux = n;

    if (M[n] == UNDEF) {
        while (aux > 0) {
            long dig = aux % 10;
            if (dig != 0) {
                res = min(res, steps(n - dig));
            }
            aux /= 10;            
        }
        M[n] = 1 + res;
    }

    return M[n];
}

int main() {
    long n;

    cin >> n;
    
    M.assign(n + 1, UNDEF);
    cout << steps(n) << "\n";
    return 0;

}