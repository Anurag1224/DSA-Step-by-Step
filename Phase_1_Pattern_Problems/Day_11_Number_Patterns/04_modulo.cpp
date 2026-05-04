// ============================================================================
// PROBLEM 4: Modulo Pattern
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (i + j) % 10 << " ";
        }
        cout << "\n";
    }
    
    return 0;
}

/*
Example (n=4):
0 1 2 3
1 2 3 4
2 3 4 5
3 4 5 6
*/
