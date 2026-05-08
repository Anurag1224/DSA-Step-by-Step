// ============================================================================
// PROBLEM 5: Custom Pattern
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        // Spaces before
        for (int j = 0; j < n - i; j++) {
            cout << " ";
        }
        
        // Left part: 1 to i
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        
        // Right part: i-1 to 1
        for (int j = i - 1; j >= 1; j--) {
            cout << j;
        }
        
        cout << "\n";
    }
    
    return 0;
}

/*
Example (n=4):
   1
  121
 12321
1234321
*/
