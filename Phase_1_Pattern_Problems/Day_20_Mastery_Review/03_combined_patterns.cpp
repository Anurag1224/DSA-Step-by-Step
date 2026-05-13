// ============================================================================
// CAPSTONE 3: Combined Patterns
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // Top half: pyramid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) cout << " ";
        for (int j = 0; j < 2 * i + 1; j++) cout << "*";
        cout << " ";
        for (int j = 0; j < 2 * i + 1; j++) cout << "*";
        cout << "\n";
    }
    
    // Bottom half: inverted pyramid
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < n - i - 1; j++) cout << " ";
        for (int j = 0; j < 2 * i + 1; j++) cout << "*";
        cout << " ";
        for (int j = 0; j < 2 * i + 1; j++) cout << "*";
        cout << "\n";
    }
    
    return 0;
}

/*
Combine multiple patterns in one output.
Shows how to orchestrate complex pattern combinations.
*/
