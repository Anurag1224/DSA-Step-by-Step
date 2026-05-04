// ============================================================================
// PROBLEM 3: Incrementing Sequence
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int num = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << num << " ";
            num++;
        }
        cout << "\n";
    }
    
    return 0;
}

/*
Example (n=4):
1
2 3
4 5 6
7 8 9 10
*/
