// ============================================================================
// PROBLEM 2: Pyramid Pattern
// ============================================================================
//
// Problem Statement:
// Print an isosceles pyramid of stars.
//
// Example:
//   Input: n = 4
//   Output:
//      *
//     ***
//    *****
//   *******
//
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
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
    
    return 0;
}

/*
KEY INSIGHT:
This is just the expanding part of a diamond.
Same formula for spaces and stars.

DRY RUN (n=4):
i=0: 3 spaces, 1 star → "   *"
i=1: 2 spaces, 3 stars → "  ***"
i=2: 1 space, 5 stars → " *****"
i=3: 0 spaces, 7 stars → "*******"
*/
