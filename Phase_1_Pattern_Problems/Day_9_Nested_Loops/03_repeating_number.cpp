// ============================================================================
// PROBLEM 3: Repeating Number Pattern
// ============================================================================
//
// Problem Statement:
// Print a triangle where row i contains the number i repeated (i+1) times.
//
// Example:
//   Input: n = 4
//   Output:
//   1
//   2 2
//   3 3 3
//   4 4 4 4
//
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cout << i << " ";
        }
        cout << "\n";
    }
    
    return 0;
}

/*
KEY INSIGHT:
Row i prints the number i exactly i times.
This requires printing the row number (i), not the column number (j).

DRY RUN (n=4):
i=1: j=0 → "1 "
i=2: j=0,1 → "2 2 "
i=3: j=0,1,2 → "3 3 3 "
i=4: j=0,1,2,3 → "4 4 4 4 "
*/
