// ============================================================================
// PROBLEM 2: Four-Way Symmetry
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < n / 2 && j < n / 2) {
                cout << "A ";
            } else if (i < n / 2 && j >= n / 2) {
                cout << "B ";
            } else if (i >= n / 2 && j < n / 2) {
                cout << "C ";
            } else {
                cout << "D ";
            }
        }
        cout << "\n";
    }
    
    return 0;
}

/*
Example (n=4):
A A B B
A A B B
C C D D
C C D D
*/
