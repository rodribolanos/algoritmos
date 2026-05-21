#include <iostream>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    long t; cin >> t;

    while (t--) {
        long n; cin >> n;
        
        long changes = 0;

        long prev = 0;
        long act;
        bool greater = true;
        for (int i = 0; i < n; i++) {
            cin >> act;
            if (greater && act > prev || (!greater && act < prev)) {
                greater = !greater;
                changes++;
            }
            prev = act;
        }
        cout << changes << "\n";
    }
    
    return 0;

}