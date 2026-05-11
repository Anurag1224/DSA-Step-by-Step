// ============================================================================
// PROBLEM 1: Hourglass Pattern
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // Top half
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) cout << " ";
        for (int j = 0; j < 2 * (n - i) - 1; j++) cout << "*";
        cout << "\n";
    }
    
    // Bottom half
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) cout << " ";
        for (int j = 0; j < 2 * i - 1; j++) cout << "*";
        cout << "\n";
    }
    
    return 0;
}

/*
Example (n=4):
*******
 *****
  ***
   *
  ***
 *****
*******
*/
