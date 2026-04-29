#include <iostream>
#include <vector>

using namespace std;

vector<int> prices;
vector<int> pages;

vector<vector<int>> M;

const long NEG_INF = -1e18;
int NIL = -1;

// maxPags me dice cual es la maxima cantidad de paginas que me puedo llevar desde el libro de precio pi
// hasta p0 con limite de paginas limitePags

long maxPags(size_t i, long limitePrecio) {
    if (limitePrecio < 0) return NEG_INF;
    if (limitePrecio == 0 or i == 0) return 0; 

    if (M[i][limitePrecio] == NIL) {
        M[i][limitePrecio] = max(maxPags(i-1, limitePrecio), 
                            pages[i-1] + maxPags(i-1, limitePrecio - prices[i - 1]));
    }

    return M[i][limitePrecio];
}

int main() {
    int n; cin >> n;
    int x; cin >> x;

    prices.assign(n, 0);
    pages.assign(n, 0);

    for (auto& h: prices) cin >> h;
    for (auto& s : pages) cin >> s;

    M.assign(n+1, vector<int>(x + 1, NIL));

    cout << maxPags(n, x) << "\n";
    return 0;    
}