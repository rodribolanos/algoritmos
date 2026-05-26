#include <iostream>

using namespace std;

int main() {
    long long mid;
    long long l = 1;
    long long r = 1e9 + 1;

    while (l <= (r - 1)) {
        mid = (l + r) / 2;
        cout << "? " << mid << "\n";
        string ans; 
        cin >> ans;

        if (ans == "YES") {
            l = mid + 1;
        } else if (ans == "NO") {
            r = mid;
        }
    }

    cout << "! " << l << "\n";

    return 0;
}