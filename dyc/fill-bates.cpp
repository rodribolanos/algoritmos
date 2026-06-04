#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


map<char, vector<long>> mapa;
string s;
string testCase;

// devuelve los indices
pair<long, long> match(long left, long right, long minIndex) {
    // busco intervalo semiabierto [L;R)
    if (left == right - 1) {
        char letter = testCase[left];
        vector<long> indexes = mapa[letter];
        auto index = upper_bound(indexes.begin(), indexes.end(), minIndex);
        
        if (index == indexes.end()) {
            // si es igual a end es que no existe
            return {-1, -1};
        } else {
            
            long foundIndex = *index;
            return {foundIndex, foundIndex};
            
        }
    }

    long mid = (right + left) / 2;

    pair<long, long> l1 = match(left, mid, minIndex);
    pair<long, long> r1 = match(mid, right, l1.second);

    if (l1.second < r1.first) {
        return {l1.first, r1.second};
    } else {
        return {-1, -1};
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    

    for (int i = 0; i < s.size(); i++) {
        char l = s[i];
        mapa[l].push_back(i);
    }

    long t; cin >> t;

    for (int p = 0; p < t; p++) {
        string st; cin >> st;
        testCase = st;
        pair<long, long> result = match(0, st.size(), -1);

        if (result.first == -1) {
            cout << "Not matched" << "\n";
        } else {
            cout << "Matched " << result.first << " " << result.second << "\n";
        }
    }
}