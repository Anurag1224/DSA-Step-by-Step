// ============================================================================
// PROBLEM 3: Alternating Pattern
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            // Odd rows: increasing
            for (int j = 1; j <= i; j++) {
                cout << j << " ";
            }
        } else {
            // Even rows: decreasing
            for (int j = i; j >= 1; j--) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    
    return 0;
}

/*
Example (n=5):
1
2 1
1 2 3
4 3 2 1
1 2 3 4 5
*/
