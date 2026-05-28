#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long l = 1;
    long long r = 100000001;

    //buscamos [l;r)
    while (l + 1 < r) {
        long long mid = (l + r) / 2;
        cout << "? " << mid << endl;
        string ans;
        cin >> ans;

        if (ans == "YES") {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << "! " << l << endl;    
    return 0;
}