#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    int M;

    while (cin >> N >> M and (M != 0  and N != 0)) {
        set<int> discs;
        int shared = 0;

        for (int n = 0; n < N; n++) {
            int disc;
            cin >> disc;
            discs.insert(disc);
        }

        for (int m = 0; m < M; m++) {
            int disc;
            cin >> disc;
            auto it = discs.find(disc);
            if(it != discs.end()) shared++;
        }

        cout << shared << "\n";
    }
    return 0;
}