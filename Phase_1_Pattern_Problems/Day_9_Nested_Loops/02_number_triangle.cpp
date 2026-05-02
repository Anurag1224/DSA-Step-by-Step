// ============================================================================
// PROBLEM 2: Number Triangle (1 to n)
// ============================================================================
//
// Problem Statement:
// Print a triangle where row i contains numbers from 1 to (i+1).
//
// Example:
//   Input: n = 4
//   Output:
//   1
//   1 2
//   1 2 3
//   1 2 3 4
//
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << "\n";
    }
    
    return 0;
}

/*
KEY INSIGHT:
Instead of printing stars, print numbers.
Row i prints numbers from 1 to i.

DRY RUN (n=4):
i=1: j=1 → "1 "
i=2: j=1,2 → "1 2 "
i=3: j=1,2,3 → "1 2 3 "
i=4: j=1,2,3,4 → "1 2 3 4 "
*/
