// ============================================================================
// PROBLEM 1: Increasing Decreasing Triangle
// ============================================================================
//
// Problem Statement:
// Print first increasing triangle then decreasing triangle of stars.
//
// Example:
//   Input: n = 3
//   Output:
//   *
//   **
//   ***
//   ***
//   **
//   *
//
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // Increasing part (already learned in Day 8)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    
    // Decreasing part (already learned in Day 8)
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    
    return 0;
}

/*
KEY INSIGHT:
We use two separate sets of nested loops.
First loop handles increasing, second handles decreasing.

DRY RUN (n=3):
Increasing: i=0,1,2 → 1,2,3 stars
Decreasing: i=2,1,0 → 3,2,1 stars (but we skip 0 stars part)

Note: The decreasing part starts from n-1 to avoid duplicate.
*/
