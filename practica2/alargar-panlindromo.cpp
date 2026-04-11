#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

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


int main() { 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string line;

    while (cin >> line) {
        string reverse = string(line.rbegin(), line.rend());
        vector<int> z = zarray(reverse + "$" + line);
        int maxPalindromic = 0;

        for (size_t i = line.size() + 1; i < z.size(); i++) {
            // busco el sufijo que tambien es palindromo. de abba, seria abba. de pepito, seria unicamente la o.
            if (i + z[i] == z.size()) {
                maxPalindromic = z[i];
                break; // el primero ya es el más largo
    }        }
        cout << line + reverse.substr(maxPalindromic) << "\n";
    }

    return 0;
}