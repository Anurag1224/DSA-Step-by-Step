// ============================================================================
// PROBLEM 4: Print Right Triangle
// ============================================================================
//
// Problem Statement:
// Given an integer n, print a right-angled triangle of stars.
//
// Example:
//   Input: n = 4
//   Output:
//   *
//   **
//   ***
//   ****
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
    
    // Row loop
    for (int i = 0; i < n; i++) {
        // Column loop: print (i+1) stars in row i
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    
    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Time Complexity: O(n²) — sum of 1+2+3+...+n = n(n+1)/2
- Space Complexity: O(1)

DRY RUN (n=4):
i=0: j=0 → print "*" → "*"
i=1: j=0,1 → print "**" → "**"
i=2: j=0,1,2 → print "***" → "***"
i=3: j=0,1,2,3 → print "****" → "****"

OUTPUT:
*
**
***
****

KEY INSIGHT:
In row i (0-indexed), print (i+1) stars.
The inner loop condition is j <= i, not j < i.
*/
