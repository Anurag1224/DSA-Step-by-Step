// ============================================================================
// CAPSTONE 1: Pattern Menu System
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

void printTriangle(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) cout << "*";
        cout << "\n";
    }
}

void printPyramid(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) cout << " ";
        for (int j = 0; j < 2 * i + 1; j++) cout << "*";
        cout << "\n";
    }
}

void printDiamond(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) cout << " ";
        for (int j = 0; j < 2 * i + 1; j++) cout << "*";
        cout << "\n";
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < n - i - 1; j++) cout << " ";
        for (int j = 0; j < 2 * i + 1; j++) cout << "*";
        cout << "\n";
    }
}

int main() {
    int n, choice;
    cin >> n >> choice;
    
    switch(choice) {
        case 1: printTriangle(n); break;
        case 2: printPyramid(n); break;
        case 3: printDiamond(n); break;
        default: cout << "Invalid choice\n";
    }
    
    return 0;
}

/*
A menu-driven pattern system.
Users can select which pattern to print.
Foundation for larger pattern applications.
*/
