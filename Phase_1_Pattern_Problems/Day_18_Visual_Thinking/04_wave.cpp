// ============================================================================
// PROBLEM 4: Wave Pattern
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int colPos = (i * 2) % (2 * n);
        if (colPos >= n) colPos = 2 * n - colPos - 1;
        
        for (int j = 0; j < n; j++) {
            if (j == colPos) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << "\n";
    }
    
    return 0;
}

/*
Example (n=4):
*
  *
    *
  *
*/
