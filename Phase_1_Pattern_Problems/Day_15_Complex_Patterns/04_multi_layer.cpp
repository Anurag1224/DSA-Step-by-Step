// ============================================================================
// PROBLEM 4: Multi-Layer Pyramid
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int layer = 1; layer <= n; layer++) {
        for (int i = 1; i <= layer; i++) {
            for (int j = 0; j < n - i + 1; j++) {
                cout << " ";
            }
            for (int j = 1; j <= i; j++) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    
    return 0;
}

/*
Example (n=3):
  1
  1  2
  1  2  3
   1
   1  2
   1  2  3
    1
    1  2
    1  2  3
*/
