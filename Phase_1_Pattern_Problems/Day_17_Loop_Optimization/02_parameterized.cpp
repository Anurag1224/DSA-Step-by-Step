// ============================================================================
// PROBLEM 2: Parameterized Pattern
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

void printPattern(int n, char symbol) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << symbol;
        }
        cout << "\n";
    }
}

int main() {
    int n;
    char symbol;
    cin >> n >> symbol;
    
    printPattern(n, symbol);
    
    return 0;
}

/*
Generalize patterns using parameters.
Same logic, different input = different output.
*/
