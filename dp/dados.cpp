#include <iostream>
#include <vector> 

using namespace std;

int caras = 6;
long long NIL = -1;
int MOD = 1e9+7;

vector<long long> M;

long long dice(long n) {
    if (n < 0) return 0;
    if (n == 0) return 1;

    if (M[n] == NIL) {
        M[n] = 0;
        for (int i = 1; i <= 6; i++) {    
            M[n] = (M[n] + dice(n-i)) % MOD;
        }
    }

    return M[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;

    M.assign(n+1, NIL);

    cout << dice(n) << "\n";
    return 0;
}