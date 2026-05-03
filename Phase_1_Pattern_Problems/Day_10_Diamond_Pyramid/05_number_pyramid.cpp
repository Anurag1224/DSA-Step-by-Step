// ============================================================================
// PROBLEM 5: Number Pyramid
// ============================================================================
//
// Problem Statement:
// Print a pyramid where row i contains numbers from 1 to (i+1) centered.
//
// Example:
//   Input: n = 4
//   Output:
//      1
//     1 2
//    1 2 3
//   1 2 3 4
//
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        // Print (n-i) spaces for centering
        for (int j = 0; j < n - i; j++) {
            cout << " ";
        }
        // Print numbers 1 to i
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << "\n";
    }
    
    return 0;
}

/*
KEY INSIGHT:
Row i has (n-i) leading spaces and numbers 1 to i.

DRY RUN (n=4):
i=1: 3 spaces, "1 " → "   1 "
i=2: 2 spaces, "1 2 " → "  1 2 "
i=3: 1 space, "1 2 3 " → " 1 2 3 "
i=4: 0 spaces, "1 2 3 4 " → "1 2 3 4 "
*/
