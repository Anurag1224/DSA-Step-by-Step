#include <bits/stdc++.h>
using namespace std;

/*
Problem: Factorial with Recursion
Calculate n! using recursive approach.
Observe how stack depth increases with n.

Time: O(n)
Space: O(n) stack space
*/

long long factorial(int n) {
    // Base case: 0! = 1, 1! = 1
    if (n <= 1) {
        return 1;
    }

    // Recursive case: n! = n * (n-1)!
    return n * factorial(n - 1);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    if (n < 0) {
        cout << "Factorial not defined for negative numbers" << endl;
        return 1;
    }

    cout << n << "! = " << factorial(n) << endl;

    // For large n, this will cause stack overflow
    // Try n=10000 to see the crash

    return 0;
}