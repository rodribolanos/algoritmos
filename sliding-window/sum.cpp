#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

int main() {
    long long n, windowSize, x, a, b, c;

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

    // first sum
    long long sum = accumulate(list.begin(), list.begin() + min((size_t) windowSize, list.size()), 0LL);
    
    long long out = sum;
    left++;
    right++;
    while (right < list.size()) {
        sum = sum - list[left] + list[right];

        left++;
        right++;
        out = out ^ sum;
    }


    cout << out << "\n";
    return 0;
}