#include <iostream>
#include <vector>

using namespace std;

vector<int> zarray(const string& s) {
    vector<int> z(s.size(), 0);
    z[0] = -1;
    for(int l = 0, i = 1, r = 1; i < s.size(); ++i) {
        if((z[i] = min(z[i-l], r-i)) < r-i) continue;
        for(l = i; r < s.size() and s[r-l] == s[r]; ++r);
        z[i] = r-l;
        if(r == i) ++r;
    }
    return z;
}

/*
IDEA: Con Z matching buscar el z[i] tal que z[i] + i = s.size(), y ademas s.size() % i == 0
i seria el periodo donde se empieza a repetir
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;

    bool first = true;
    while (t--) {
        string separator; if (!first) cin >> separator;
        string word;
        cin >> word;
        first = false;

        vector<int> z = zarray(word);

        // el mas chico es la longitud si no hay periodo
        int n = word.size();
        int lessPeriod = n;
        for (int i = 1; i < z.size(); i++) {
            if (z[i] + i == n && n % i == 0) {
                lessPeriod = min(i, lessPeriod);
                break;
            }
        }

        cout << lessPeriod;

        if (t != 1) cout << "\n\n";
    }
}