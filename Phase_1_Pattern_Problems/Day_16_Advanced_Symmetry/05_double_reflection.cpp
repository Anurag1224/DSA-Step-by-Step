// ============================================================================
// PROBLEM 5: Double Reflection
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // Left half
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i || j == n - i - 1) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << "| ";
        // Right half (mirror)
        for (int j = n - 1; j >= 0; j--) {
            if (j == i || j == n - i - 1) {
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
Example (n=4):
*       | *
  *   * |   * *
*   *   |   * *
*       | *
*/
