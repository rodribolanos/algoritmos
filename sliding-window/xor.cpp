#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

int main() {
    long long n, x, a, b, c;
    size_t windowSize;

    cin >> n >> windowSize;

    cin >> x >> a >> b >> c;

    vector<long long> list;

    list.push_back(x);

    for (int i = 2; i <= n; i++) {
        long num = (a * list[i-2] + b) % c;
        list.push_back(num);
    }
    
    long left = -1;
    long right = windowSize - 1;

    long long xors = 0;
    // first xor
    for (int i = 0; i < min(windowSize, list.size()); i++) {
        xors = xors ^ list[i];
    }
    
    long long out = xors;
    left++;
    right++;
    while (right < list.size()) {
        xors = xors ^ list[left] ^ list[right];

        left++;
        right++;
        out = out ^ xors;
    }


    cout << out << "\n";
    return 0;
}