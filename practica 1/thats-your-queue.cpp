#include <iostream>
#include <list>
using namespace std; 

int MAX_TEST_CASES = 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int P;
    int C;
    int cases = 0;

    while (cin >> P >> C and (P!= 0 and C != 0)) {
        bool flag = true;
        list<int> cola(P);
        cases++;

        for (int p = 1; p <= P; p++) {
            cola.push_back(p);
        }

        for (int i = 0; i < C; i++) {
            char command;
            cin >> command;

            if (command == 'N') {
                if (flag) cout << "Case " << cases << ":" << "\n";
                flag = false;
                int number = *cola.begin();
                cout << number << "\n";
                cola.pop_front();
                cola.push_back(number);
            } else {
                int number;
                cin >> number;
                cola.remove(number);
                cola.push_front(number);
            }
        }
    }
    return 0;
}