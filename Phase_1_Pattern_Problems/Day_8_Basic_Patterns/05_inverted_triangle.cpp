// ============================================================================
// PROBLEM 5: Print Inverted Right Triangle
// ============================================================================
//
// Problem Statement:
// Given an integer n, print an inverted right-angled triangle of stars.
//
// Example:
//   Input: n = 4
//   Output:
//   ****
//   ***
//   **
//   *
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
        // Column loop: print (n-i) stars in row i
        for (int j = 0; j < n - i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    
    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Time Complexity: O(n²)
- Space Complexity: O(1)

DRY RUN (n=4):
i=0: j=0,1,2,3 → print 4 stars → "****"
i=1: j=0,1,2 → print 3 stars → "***"
i=2: j=0,1 → print 2 stars → "**"
i=3: j=0 → print 1 star → "*"

OUTPUT:
****
***
**
*

KEY INSIGHT:
In row i (0-indexed), print (n-i) stars.
The inner loop condition is j < (n-i).
*/
