// ============================================================================
// PROBLEM 4: Alphabet Triangle
// ============================================================================
//
// Problem Statement:
// Print a triangle where row i contains letters from A to the (i+1)th letter.
//
// Example:
//   Input: n = 4
//   Output:
//   A
//   A B
//   A B C
//   A B C D
//
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << (char)('A' + j) << " ";
        }
        cout << "\n";
    }
    
    return 0;
}

/*
KEY INSIGHT:
Convert numbers to characters using ASCII.
'A' + 0 = 'A', 'A' + 1 = 'B', etc.

DRY RUN (n=4):
i=0: j=0 → 'A' + 0 = 'A' → "A "
i=1: j=0,1 → 'A', 'B' → "A B "
i=2: j=0,1,2 → 'A', 'B', 'C' → "A B C "
i=3: j=0,1,2,3 → 'A', 'B', 'C', 'D' → "A B C D "
*/
