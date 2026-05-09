// ============================================================================
// PROBLEM 4: Diagonal Bands
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ((i + j) % 3) << " ";
        }
        cout << "\n";
    }
    
    return 0;
}

/*
Example (n=5):
0 1 2 0 1
1 2 0 1 2
2 0 1 2 0
0 1 2 0 1
1 2 0 1 2
*/
