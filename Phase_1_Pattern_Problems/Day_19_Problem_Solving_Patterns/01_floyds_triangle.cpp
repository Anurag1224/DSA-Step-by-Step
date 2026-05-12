// ============================================================================
// PROBLEM 1: Floyd's Triangle
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int num = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cout << num++ << " ";
        }
        cout << "\n";
    }
    
    return 0;
}

/*
Classic interview pattern.
Example (n=4):
1
2 3
4 5 6
7 8 9 10
*/
