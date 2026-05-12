// ============================================================================
// PROBLEM 5: Spiral Pattern
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> spiral(n, vector<int>(n, 0));
    
    int num = 1;
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) {
            spiral[top][j] = num++;
        }
        top++;
        
        for (int i = top; i <= bottom; i++) {
            spiral[i][right] = num++;
        }
        right--;
        
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                spiral[bottom][j] = num++;
            }
            bottom--;
        }
        
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                spiral[i][left] = num++;
            }
            left++;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << spiral[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}

/*
Advanced spiral pattern generation.
Example (n=3):
1 2 3
8 9 4
7 6 5
*/
