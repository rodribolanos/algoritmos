    #include <iostream>
    #include <algorithm>

    using namespace std; 

vector<int> zarray(const string& s) {
    vector<int> z(s.size(), s.size());
    for(int l = 0, i = 1, r = 1; i < s.size(); ++i) {
        if((z[i] = min(z[i-l], r-i)) < r-i) continue;
        for(l = i; r < s.size() and s[r-l] == s[r]; ++r);
        z[i] = r-l;
        if(r == i) ++r;
    }
    return z;
}

bool isPalindrome(const string& text) {
    
    // chequea si son palindromos en O(N).
    // INVARIANTES: l <= r + 1 en todo el programa.

    int l = 0;
    int r = text.size() - 1;

    while (l < r and text[l] == text[r]) {
        l++;
        r--;
    }

    return (l >= r);
}

bool isAllindrome(const string& text) {
     
}

int main() {
    int testCases;

    cin >> testCases;

    vector<string> results(testCases);


    for (int tc = 0; tc < testCases; tc++) {
        string text;
        cin >> text;
        bool isPalindrome = isPalindrome(text);
        bool isAllindrome = isAllindrome(text);

        if (isPalindrome) {
            results.push_back("palindrome");
            return 0;
        }
            
        if (isAllindrome) {
            results.push_back("allindrome");
            return 0;
        }

        results.push_back("simple");
    }


    for (size_t i = 0; i < results.size(); ++i) {
        cout << results[i];
        if (i < results.size() - 1) {
            cout << "\n";
            // endl hace flush, \n no 
        }
    }
    return 0;
}