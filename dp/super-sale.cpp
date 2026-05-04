#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> prices;
vector<int> weights;

vector<vector<long>> M;


const long NEG_INF = -1e18;
int NIL = -1;
long MW = 30;


long mochila(size_t i, long k ) {
    if (k < 0) return NEG_INF;
    if (k == 0 or i == 0) return 0; 

    if (M[i][k] == NIL) {
        M[i][k] = max(mochila(i-1, k), 
                            prices[i-1] + mochila(i-1, k - weights[i - 1]));
    }

    return M[i][k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        prices.assign(n, 0);
        weights.assign(n, 0);

        M.assign(n+1, vector<long>(MW + 1, NIL));

        for (int elem = 0; elem < n; elem++) {
            cin >> prices[elem];
            cin >> weights[elem];
        }

        int g; cin >> g;
        long sum = 0;
        for (int person = 0; person < g; person++) {
            int maxWeight; cin >> maxWeight;
            sum += mochila(n, maxWeight);
        }
        
        cout << sum << "\n";
    }
    
    return 0;
}