// ============================================================================
// PROBLEM 2: Combined Triangles
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // Triangle 1: increasing
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cout << i << " ";
        }
        cout << "\n";
    }
    
    // Triangle 2: decreasing
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            cout << i << " ";
        }
        cout << "\n";
    }
    
    return 0;
}

/*
Example (n=3):
1
2 2
3 3 3
2 2
1
*/
