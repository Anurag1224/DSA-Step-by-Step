// ============================================================================
// PROBLEM 3: Inverted Pyramid
// ============================================================================
//
// Problem Statement:
// Print an inverted isosceles pyramid of stars.
//
// Example:
//   Input: n = 4
//   Output:
//   *******
//    *****
//     ***
//      *
//
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        // Print i spaces
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        // Print (2*(n-i-1)+1) stars
        for (int j = 0; j < 2 * (n - i - 1) + 1; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    
    return 0;
}

/*
KEY INSIGHT:
Inverted pyramid starts with maximum stars and decreases.
Row i has:
- Spaces: i
- Stars: 2*(n-i-1)+1

DRY RUN (n=4):
i=0: 0 spaces, 7 stars → "*******"
i=1: 1 space, 5 stars → " *****"
i=2: 2 spaces, 3 stars → "  ***"
i=3: 3 spaces, 1 star → "   *"
*/
