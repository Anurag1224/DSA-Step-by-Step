// ============================================================================
// PROBLEM 1: 180-Degree Rotation
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<string> lines;
    
    // Generate top half
    for (int i = 1; i <= n; i++) {
        string line = "";
        for (int j = 0; j < i; j++) {
            line += "*";
        }
        lines.push_back(line);
    }
    
    // Print top half
    for (auto& line : lines) {
        for (int j = 0; j < n - line.size(); j++) {
            cout << " ";
        }
        cout << line << "\n";
    }
    
    // Print rotated (bottom half)
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < n - i; j++) {
            cout << " ";
        }
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    
    return 0;
}

/*
Example (n=3):
  *
 **
***
 **
  *
*/
