// ============================================================================
// PROBLEM 3: Triangular Grid
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << (i + j + 1) % 10 << " ";
        }
        cout << "\n";
    }
    
    return 0;
}

/*
Example (n=4):
1
2 3
3 4 5
4 5 6 7
*/
