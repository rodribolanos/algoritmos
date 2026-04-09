#include <iostream>
#include <vector> 

using namespace std; 

int calculatePeriodicStrings(string text) {
    
}

int main() {
    int testCases;

    vector<int> results(testCases, 0);

    for (int i = 0; i < testCases; i++) { 
        string text;
        cin >> text;

        results[i] = calculatePeriodicStrings(text);
    }

    for (int r = 0; r < testCases; r++) {
        cout << results[r] << endl;
    }
    return 0;
}