#include <iostream>
#include <vector>

using namespace std;

int m; int n;
long NIL = -1;
long INF = 1e7;

vector<pair<long, long>> M;

pair<int,int> best(pair<int,int> a, pair<int,int> b) {
    if (a.second != b.second)
        return (a.second < b.second ? a : b);
    return (a.first > b.first ? a : b);
}

/*
homer(t) es la maxima cantidad de hamburguesas que puede comer homero en el timepo t
si le sobra tiempo, va en el segundo elemento del par
*/
pair<long, long> homer(long t) {
    if (t < 0) return {-INF, INF};
    if (t == 0) return {0, 0};

    if (M[t].first == NIL) {
        auto mburguer = homer(t-m);
        auto nburguer = homer(t-n);
        mburguer.first++;
        nburguer.first++;
        M[t] = best(
            {0, t},// quedarme aca
            best(
                mburguer, nburguer
            )// el mejor de avanzar en t o en m
        );
    }

    return M[t];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    while (cin >> m && cin >> n && cin >> t) {
        M.assign(t + 1, {NIL, NIL});
        pair<long, long> burgers = homer(t);
        if (burgers.second == 0)
            cout << burgers.first << "\n";
        else
            cout << burgers.first << " " << burgers.second << "\n"; 
    }

    return 0;
}