// ============================================================================
// PROBLEM 5: Complete Symmetry
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // Top-left to bottom-right
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << "\n";
    }
    
    // Mirror in opposite diagonal
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << "\n";
    }
    
    return 0;
}

/*
Example (n=3):
*    
  *  
    *
  *  
*    
*/
