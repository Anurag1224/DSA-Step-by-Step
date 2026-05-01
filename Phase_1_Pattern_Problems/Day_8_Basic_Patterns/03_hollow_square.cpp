// ============================================================================
// PROBLEM 3: Print Hollow Square
// ============================================================================
//
// Problem Statement:
// Given an integer n, print a hollow square of stars with side length n.
// Edges should be stars, interior should be spaces.
//
// Example:
//   Input: n = 4
//   Output:
//   ****
//   *  *
//   *  *
//   ****
//
// Constraints:
//   2 ≤ n ≤ 100
//
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // First row, last row, first column, or last column → print star
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                cout << "*";
            } else {
                // Interior → print space
                cout << " ";
            }
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
i=0: j=0,1,2,3 → all are edge (i==0) → "****"
i=1: j=0 (edge) → "*", j=1,2 (interior) → " ", " ", j=3 (edge) → "*" → "*  *"
i=2: j=0 (edge) → "*", j=1,2 (interior) → " ", " ", j=3 (edge) → "*" → "*  *"
i=3: j=0,1,2,3 → all are edge (i==3) → "****"

OUTPUT:
****
*  *
*  *
****

KEY INSIGHT:
We check conditions based on row (i) and column (j) indices:
- First/last row: i == 0 or i == n-1
- First/last column: j == 0 or j == n-1
*/
