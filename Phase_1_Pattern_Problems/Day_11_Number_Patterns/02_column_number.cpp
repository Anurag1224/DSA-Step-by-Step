// ============================================================================
// PROBLEM 2: Column Numbers Pattern
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= i + 1; j++) {
            cout << j << " ";
        }
        cout << "\n";
    }
    
    return 0;
}

/*
Example (n=4):
1
1 2
1 2 3
1 2 3 4
*/
