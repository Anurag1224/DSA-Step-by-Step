// ============================================================================
// PROBLEM 3: Multiple Pattern Generator
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

void printPyramid(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) cout << " ";
        for (int j = 0; j < 2 * i + 1; j++) cout << "*";
        cout << "\n";
    }
}

void printTriangle(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) cout << "*";
        cout << "\n";
    }
}

int main() {
    int n, choice;
    cin >> n >> choice;
    
    if (choice == 1) printPyramid(n);
    else if (choice == 2) printTriangle(n);
    
    return 0;
}

/*
Use functions to handle different pattern types.
Improves code organization and reusability.
*/
