// ============================================================================
// PROBLEM 2: Print Rectangle Pattern
// ============================================================================
//
// Problem Statement:
// Given two integers rows and cols, print a rectangle of stars.
//
// Example:
//   Input: rows = 2, cols = 5
//   Output:
//   *****
//   *****
//
// Constraints:
//   1 ≤ rows, cols ≤ 100
//
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;
    
    // Row loop: iterate 'rows' times
    for (int i = 0; i < rows; i++) {
        // Column loop: print 'cols' stars in this row
        for (int j = 0; j < cols; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    
    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Time Complexity: O(rows × cols)
- Space Complexity: O(1)

DRY RUN (rows=2, cols=5):
i=0: j=0,1,2,3,4 → print "*****" → print newline
i=1: j=0,1,2,3,4 → print "*****" → print newline

OUTPUT:
*****
*****
*/
