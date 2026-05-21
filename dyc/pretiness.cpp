#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;


// sum array me dice si existe un subarray compuesto por elementos menores o mayores que el mid ((max + min) / 2) que sumen sumTarget
bool isSumSubArray(vector<long>& array, long sumTarget) {
    if (array.size() == 0) return false;
    if (accumulate(array.begin(), array.end(), 0) == sumTarget) return true;
    if (accumulate(array.begin(), array.end(), 0) < sumTarget) return false;

    long max = *max_element(array.begin(), array.end());
    long min = *min_element(array.begin(), array.end());

    if (max == min) return false;
    
    long mid = (max + min) / 2;

    vector<long> left; 
    vector<long> right;

    for (long num : array) {
        if (num > mid) {
            right.push_back(num);
        } else {
            left.push_back(num);
        }
    }

    return isSumSubArray(left, sumTarget) || isSumSubArray(right, sumTarget);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long t; cin >> t;

    while (t--) {
        long n; long q;
        cin >> n >> q;

        vector<long> array(n);

        for (int i = 0; i < n; i++) {
            cin >> array[i];
        }

        long k;
        for (int p = 0; p < q; p++) {
            cin >> k;
            if (isSumSubArray(array, k)) {
                cout << "Yes" << "\n";
            } else {
                cout << "No" << "\n";
            }
        }
    }
    return 0;
}