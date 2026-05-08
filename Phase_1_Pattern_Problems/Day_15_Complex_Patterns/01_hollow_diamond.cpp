// ============================================================================
// PROBLEM 1: Nested Shapes
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // Outer diamond
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == 2 * i) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << "\n";
    }
    
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            if (j == 0 || j == 2 * i) {
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
Example (n=3):
  *
 * *
*   *
 * *
  *
*/
