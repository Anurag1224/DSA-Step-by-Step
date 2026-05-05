// ============================================================================
// PROBLEM 4: Double Triangle
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // Left triangle
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        cout << " ";
        // Right triangle
        for (int j = 0; j < n - i + 1; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    
    return 0;
}

/*
Example (n=4):
*  ****
** ***
*** **
**** *
*/
