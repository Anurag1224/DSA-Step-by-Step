// ============================================================================
// PROBLEM 1: Diamond Pattern
// ============================================================================
//
// Problem Statement:
// Print a diamond pattern of stars with side length n.
//
// Example:
//   Input: n = 3
//   Output:
//     *       (2 spaces, 1 star)
//    ***      (1 space, 3 stars)
//   *****     (0 spaces, 5 stars)
//    ***      (1 space, 3 stars)
//     *       (2 spaces, 1 star)
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
        // Print (2*i+1) stars
        for (int j = 0; j < 2 * i + 1; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    
    // Contracting part
    for (int i = n - 2; i >= 0; i--) {
        // Print (n-i-1) spaces
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        // Print (2*i+1) stars
        for (int j = 0; j < 2 * i + 1; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    
    return 0;
}

/*
KEY INSIGHT:
Row i has:
- Spaces: (n - i - 1)
- Stars: (2*i + 1)

DRY RUN (n=3):
Expanding:
i=0: 2 spaces, 1 star → "  *"
i=1: 1 space, 3 stars → " ***"
i=2: 0 spaces, 5 stars → "*****"

Contracting (i=1,0):
i=1: 1 space, 3 stars → " ***"
i=0: 2 spaces, 1 star → "  *"
*/
