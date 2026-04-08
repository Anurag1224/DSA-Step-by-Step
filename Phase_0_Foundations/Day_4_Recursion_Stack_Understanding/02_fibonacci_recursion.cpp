#include <bits/stdc++.h>
using namespace std;

/*
Problem: Fibonacci with Recursion
Calculate nth Fibonacci number using naive recursion.
Demonstrates exponential time complexity O(2^n).

Time: O(2^n) - very slow for n > 40
Space: O(n) stack space
*/

long long fibonacci(int n) {
    // Base cases
    if (n == 0) return 0;
    if (n == 1) return 1;

    // Recursive case: F(n) = F(n-1) + F(n-2)
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    if (n < 0) {
        cout << "Fibonacci not defined for negative numbers" << endl;
        return 1;
    }

    cout << "F(" << n << ") = " << fibonacci(n) << endl;

    // For n=40, this takes several seconds
    // For n=50, it takes minutes/hours
    // Stack depth is only n, but time explodes

    return 0;
}