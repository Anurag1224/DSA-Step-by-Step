// ============================================================================
// PROBLEM 3: Pascal's Triangle
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int val = 1;
        for (int j = 0; j <= i; j++) {
            cout << val << " ";
            val = val * (i - j) / (j + 1);
        }
        cout << "\n";
    }
    
    return 0;
}

/*
Famous mathematical pattern.
Example (n=5):
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
*/
