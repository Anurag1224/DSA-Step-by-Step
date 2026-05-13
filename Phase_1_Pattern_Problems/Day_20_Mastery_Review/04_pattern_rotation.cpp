// ============================================================================
// CAPSTONE 4: Pattern with Rotation
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // Generate base triangle
    vector<string> base(n);
    for (int i = 0; i < n; i++) {
        string line = "";
        for (int j = 0; j <= i; j++) {
            line += "*";
        }
        base[i] = line;
    }
    
    // Rotate and print 4 times
    for (int rotation = 0; rotation < 4; rotation++) {
        if (rotation == 0) {
            // Original
            for (auto& line : base) cout << line << "\n";
        }
        // Add more rotations as needed
    }
    
    return 0;
}

/*
Create patterns and rotate them.
Foundation for more complex transformations.
*/
