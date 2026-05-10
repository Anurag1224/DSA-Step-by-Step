// ============================================================================
// PROBLEM 1: Helper Function Pattern
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

void printSpaces(int count) {
    for (int i = 0; i < count; i++) {
        cout << " ";
    }
}

void printStars(int count) {
    for (int i = 0; i < count; i++) {
        cout << "*";
    }
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        printSpaces(n - i - 1);
        printStars(2 * i + 1);
        cout << "\n";
    }
    
    return 0;
}

/*
Uses helper functions to reduce code duplication.
Much cleaner than writing loops directly.
*/
