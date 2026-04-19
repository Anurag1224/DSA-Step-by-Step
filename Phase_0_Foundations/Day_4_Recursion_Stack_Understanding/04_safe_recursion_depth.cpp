#include <bits/stdc++.h>
using namespace std;

/*
Problem: Safe Recursion Depth
Implement factorial with recursion depth checking.
Prevents stack overflow crashes in production code.

Time: O(n)
Space: O(n) stack space (but bounded)
*/

const int MAX_RECURSION_DEPTH = 10000;  // Safe limit

long long safe_factorial(int n, int current_depth = 0) {
    // Check recursion depth to prevent stack overflow
    if (current_depth > MAX_RECURSION_DEPTH) {
        throw runtime_error("Recursion depth exceeded maximum safe limit");
    }

    // Base case
    if (n <= 1) {
        return 1;
    }

    // Recursive case with depth tracking
    return n * safe_factorial(n - 1, current_depth + 1);
}

// Alternative: Iterative factorial (no recursion depth issues)
long long iterative_factorial(int n) {
    if (n < 0) return 0;  // Error case

    long long result = 1;
    for (int i = 2; i <= n; i++) {
        // Check for overflow (though long long can handle large n)
        if (result > LLONG_MAX / i) {
            throw runtime_error("Factorial result too large for long long");
        }
        result *= i;
    }
    return result;
}