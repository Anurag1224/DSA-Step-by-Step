// ============================================================================
// PROBLEM 2: Gradient Pattern
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int minDist = min({i, j, n - 1 - i, n - 1 - j});
            cout << minDist << " ";
        }
        cout << "\n";
    }
    
    return 0;
}

/*
Example (n=5):
0 0 0 0 0
0 1 1 1 0
0 1 2 1 0
0 1 1 1 0
0 0 0 0 0
*/
