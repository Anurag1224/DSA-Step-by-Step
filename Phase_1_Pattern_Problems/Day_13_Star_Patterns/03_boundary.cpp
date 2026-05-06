// ============================================================================
// PROBLEM 3: Boundary Stars
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
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
* * * *
*     *
*     *
* * * *
*/
