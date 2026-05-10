// ============================================================================
// PROBLEM 5: Flexible Pattern Engine
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

void printRow(int spaces, int content, char contentChar, char padding = ' ') {
    for (int i = 0; i < spaces; i++) cout << padding;
    for (int i = 0; i < content; i++) cout << contentChar;
    cout << "\n";
}

int main() {
    int n;
    cin >> n;
    
    // Pyramid
    for (int i = 0; i < n; i++) {
        printRow(n - i - 1, 2 * i + 1, '*');
    }
    
    cout << "\n";
    
    // Triangle
    for (int i = 0; i < n; i++) {
        printRow(0, i + 1, '*');
    }
    
    return 0;
}

/*
Create a flexible function that handles many pattern variations.
This is the foundation of good code design.
*/
