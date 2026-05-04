// ============================================================================
// PROBLEM 1: Row Numbers Pattern
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cout << i << " ";
        }
        cout << "\n";
    }
    
    return 0;
}

/*
Example (n=4):
1
2 2
3 3 3
4 4 4 4
*/
