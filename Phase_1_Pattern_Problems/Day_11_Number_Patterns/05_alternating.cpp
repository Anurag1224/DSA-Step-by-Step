// ============================================================================
// PROBLEM 5: Alternating Pattern
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if ((i + j) % 2 == 0) {
                cout << "1 ";
            } else {
                cout << "0 ";
            }
        }
        cout << "\n";
    }
    
    return 0;
}

/*
Example (n=4):
1
0 1
1 0 1
0 1 0 1
*/
