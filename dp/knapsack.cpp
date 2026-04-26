#include <iostream> 
#include <vector>

using namespace std;

vector<vector<long>> M;


const long NEG_INF = -1e18;
int NIL = -1;
vector<int> v;
vector<int> p;

long mochila(size_t i, long k ) {
    if (k < 0) return NEG_INF;
    if (k == 0 or i == 0) return 0; 

    if (M[i][k] == NIL) {
        M[i][k] = max(mochila(i-1, k), 
                            v[i-1] + mochila(i-1, k - p[i - 1]));
    }

    return M[i][k];
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int elems; cin >> elems;
    int k; cin >> k;

    v.assign(elems, 0);
    p.assign(elems, 0);

    for (auto& e: v) cin >> e;
    for (auto& e : p) cin >> e;

    M.assign(elems+1, vector<int>(k + 1, NIL));
    cout << mochila(elems, k);
    return 0;
}