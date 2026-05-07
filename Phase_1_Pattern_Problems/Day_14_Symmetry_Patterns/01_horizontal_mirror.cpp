// ============================================================================
// PROBLEM 1: Horizontal Mirror
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        // Left side
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        // Mirror of left (excluding middle)
        for (int j = i - 1; j >= 0; j--) {
            cout << "*";
        }
        cout << "\n";
    }
    
    return 0;
}

/*
Example (n=3):
*
***
*****
*/
