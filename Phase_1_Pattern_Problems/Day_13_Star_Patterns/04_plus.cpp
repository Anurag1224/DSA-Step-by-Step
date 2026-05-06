// ============================================================================
// PROBLEM 4: Plus Pattern
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int mid = n / 2;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == mid || j == mid) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << "\n";
    }
    
    return 0;
}

/*
Example (n=5):
  *  
  *  
* * * * *
  *  
  *  
*/
