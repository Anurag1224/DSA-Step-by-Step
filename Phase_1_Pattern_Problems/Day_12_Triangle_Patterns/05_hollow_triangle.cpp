// ============================================================================
// PROBLEM 5: Nested Triangle
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (i == 1 || i == n || j == 0 || j == i - 1) {
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
**
* *
*  *
*/
