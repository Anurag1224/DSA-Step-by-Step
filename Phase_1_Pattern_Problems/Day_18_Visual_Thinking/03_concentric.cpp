// ============================================================================
// PROBLEM 3: Concentric Squares
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            int minDist = min({i, j, 2 * n - 2 - i, 2 * n - 2 - j});
            cout << (minDist % 2 ? "  " : "* ");
        }
        cout << "\n";
    }
    
    return 0;
}

/*
Example (n=3):
* * *
    * 
* * *
    *
* * *
*/
