#include <iostream>
#include <string>

#include <algorithm>

using namespace std;
int repetitions(string text) {
    int length = (int)text.length();
    
    if (length == 0) return 0;
    int repetitions = 1;
    int maxSeen = 1;
    for (int i = 1; i < length; i++) {
        if (text[i] == text[i-1]) repetitions++;
        else repetitions = 1;

        maxSeen = max(maxSeen, repetitions);
    }

    return maxSeen;
}

int main() {
    string t;

    cin >> t;

    cout << repetitions(t) << '\n';
    return 0;
}