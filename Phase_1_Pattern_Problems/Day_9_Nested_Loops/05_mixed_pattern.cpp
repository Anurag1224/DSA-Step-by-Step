// ============================================================================
// PROBLEM 5: Mixed Pattern
// ============================================================================
//
// Problem Statement:
// Print a triangle where row i contains i increasing numbers followed by
// (n-i) decreasing numbers.
//
// Example:
//   Input: n = 3
//   Output:
//   1 3 2 1
//   1 2 3 2 1
//   1 2 3 4 3 2 1
//
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        // Increasing part: 1 to i
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        // Decreasing part: i-1 to 1
        for (int j = i - 1; j >= 1; j--) {
            cout << j << " ";
        }
        cout << "\n";
    }
    
    return 0;
}

/*
KEY INSIGHT:
Each row has two parts: increasing and decreasing.
Increasing part: 1, 2, ..., i
Decreasing part: i-1, i-2, ..., 1

DRY RUN (n=3):
i=1: increasing (1) + decreasing () → "1 "
i=2: increasing (1,2) + decreasing (1) → "1 2 1 "
i=3: increasing (1,2,3) + decreasing (2,1) → "1 2 3 2 1 "
*/
