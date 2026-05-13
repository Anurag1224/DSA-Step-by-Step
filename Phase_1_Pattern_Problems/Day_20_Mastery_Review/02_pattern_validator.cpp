// ============================================================================
// CAPSTONE 2: Pattern Validator
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

bool isValidTrianglePattern(vector<string>& pattern) {
    int n = pattern.size();
    for (int i = 0; i < n; i++) {
        int expected = i + 1;
        int actual = 0;
        for (char c : pattern[i]) {
            if (c == '*') actual++;
        }
        if (actual != expected) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    vector<string> pattern(n);
    for (int i = 0; i < n; i++) {
        getline(cin, pattern[i]);
    }
    
    if (isValidTrianglePattern(pattern)) {
        cout << "VALID\n";
    } else {
        cout << "INVALID\n";
    }
    
    return 0;
}

/*
Validate if a given pattern matches expected rules.
Useful for checking pattern output correctness.
*/
