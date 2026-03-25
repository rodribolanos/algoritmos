#include <iostream>
#include <string>
#include <list>

using namespace std;

// URL: https://onlinejudge.org/external/119/11988.pdf
int main() {
    string text;

    while (getline(cin, text)) {
        list<char> outText;
        auto it = outText.begin();

        for (char c: text) {
            
            if (c == '[') {
                it = outText.begin();
            } else if (c == ']') {
                it = outText.end();
            } else {
                it = outText.insert(it, c);
                it++;
            }
        }
        
        string output(outText.begin(), outText.end());
        cout << output << "\n";
    }
    return 0;
}