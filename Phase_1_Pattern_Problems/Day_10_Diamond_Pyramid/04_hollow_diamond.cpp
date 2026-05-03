// ============================================================================
// PROBLEM 4: Hollow Diamond
// ============================================================================
//
// Problem Statement:
// Print a hollow diamond pattern.
//
// Example:
//   Input: n = 3
//   Output:
//     *
//    * *
//   *   *
//    * *
//     *
//
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // Expanding part
    for (int i = 0; i < n; i++) {
        // Print (n-i-1) spaces
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        
        cout << "*";  // First star
        
        if (i > 0) {
            // Middle spaces: 2*i - 1
            for (int j = 0; j < 2 * i - 1; j++) {
                cout << " ";
            }
            cout << "*";  // Last star
        }
        cout << "\n";
    }
    
    // Contracting part
    for (int i = n - 2; i >= 0; i--) {
        // Print (n-i-1) spaces
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        
        cout << "*";  // First star
        
        if (i > 0) {
            // Middle spaces: 2*i - 1
            for (int j = 0; j < 2 * i - 1; j++) {
                cout << " ";
            }
            cout << "*";  // Last star
        }
        cout << "\n";
    }
    
    return 0;
}

/*
KEY INSIGHT:
Print only the edges of the diamond, not filled.
First star at position (n-i-1).
Last star (if exists) has (2*i-1) spaces between them.
Single star at tip.
*/
