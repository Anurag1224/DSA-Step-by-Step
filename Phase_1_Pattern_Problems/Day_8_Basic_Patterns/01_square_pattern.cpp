// ============================================================================
// PROBLEM 1: Print Square Pattern
// ============================================================================
//
// Problem Statement:
// Given an integer n, print a square of stars with side length n.
//
// Example:
//   Input: n = 3
//   Output:
//   ***
//   ***
//   ***
//
// Constraints:
//   1 ≤ n ≤ 100
//
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // Row loop: iterate n times for each row
    for (int i = 0; i < n; i++) {
        // Column loop: print n stars in this row
        for (int j = 0; j < n; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    
    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Time Complexity: O(n²) — outer loop runs n times, inner loop runs n times
- Space Complexity: O(1) — only storing n

DRY RUN (n=3):
i=0: j=0,1,2 → print "*", "*", "*" → print newline → "***\n"
i=1: j=0,1,2 → print "*", "*", "*" → print newline → "***\n"
i=2: j=0,1,2 → print "*", "*", "*" → print newline → "***\n"

OUTPUT:
***
***
***
*/
