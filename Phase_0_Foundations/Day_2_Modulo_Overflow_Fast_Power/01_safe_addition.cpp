#include <bits/stdc++.h>
using namespace std;

/*
 * PROBLEM: Safe Addition (Overflow Detection)
 *
 * Given two integers a and b, compute their sum without causing integer overflow.
 * If overflow would occur, return a special value or throw an error.
 *
 * TIME COMPLEXITY: O(1)
 * SPACE COMPLEXITY: O(1)
 *
 * KEY CONCEPTS:
 * - Integer overflow occurs when result exceeds data type range
 * - For signed integers: INT_MIN to INT_MAX
 * - Detection: Check if (a > 0 && b > 0 && sum < 0) or (a < 0 && b < 0 && sum > 0)
 */

class SafeMath {
public:
    // Method 1: Using built-in overflow detection (C++20)
    static bool safeAdd_builtin(long long a, long long b, long long& result) {
        // In C++20, we can use std::numeric_limits
        if (__builtin_add_overflow(a, b, &result)) {
            return false; // Overflow occurred
        }
        return true;
    }

    // Method 2: Manual overflow detection
    static bool safeAdd_manual(long long a, long long b, long long& result) {
        // Check for overflow before addition
        if (a > 0 && b > 0 && a > LLONG_MAX - b) {
            return false; // Positive overflow
        }
        if (a < 0 && b < 0 && a < LLONG_MIN - b) {
            return false; // Negative overflow
        }

        result = a + b;
        return true;
    }

    // Method 3: Using wider type (if available)
    static long long safeAdd_wide(int a, int b) {
        long long result = (long long)a + b;

        // Check if result fits in int range
        if (result > INT_MAX || result < INT_MIN) {
            throw overflow_error("Integer overflow detected");
        }

        return result;
    }
};

int main() {
    cout << "=== Safe Addition Demonstration ===\n\n";

    // Test cases
    vector<pair<long long, long long>> testCases = {
        {INT_MAX, 1},           // Positive overflow
        {INT_MIN, -1},          // Negative overflow
        {1000000, 2000000},     // Normal addition
        {-1000000, -2000000},   // Normal negative addition
        {0, 0},                 // Zero case
        {INT_MAX, INT_MIN}      // Mixed signs
    };

    for (auto& test : testCases) {
        long long a = test.first, b = test.second;
        long long result_builtin, result_manual;

        cout << "Adding: " << a << " + " << b << "\n";

        // Test built-in method
        bool success_builtin = SafeMath::safeAdd_builtin(a, b, result_builtin);
        cout << "  Built-in method: " << (success_builtin ? "Success" : "Overflow")
             << " (Result: " << result_builtin << ")\n";

        // Test manual method
        bool success_manual = SafeMath::safeAdd_manual(a, b, result_manual);
        cout << "  Manual method: " << (success_manual ? "Success" : "Overflow")
             << " (Result: " << result_manual << ")\n";

        // Test wide type method (for int inputs)
        if (a >= INT_MIN && a <= INT_MAX && b >= INT_MIN && b <= INT_MAX) {
            try {
                long long result_wide = SafeMath::safeAdd_wide((int)a, (int)b);
                cout << "  Wide type method: Success (Result: " << result_wide << ")\n";
            } catch (const overflow_error& e) {
                cout << "  Wide type method: " << e.what() << "\n";
            }
        }

        cout << "\n";
    }

    // Demonstrate overflow behavior
    cout << "=== Demonstrating Actual Overflow ===\n";
    int x = INT_MAX;
    cout << "INT_MAX = " << x << "\n";
    x = x + 1;  // This overflows silently
    cout << "INT_MAX + 1 = " << x << " (Wrapped around to INT_MIN)\n";
    cout << "INT_MIN = " << INT_MIN << "\n\n";

    return 0;
}

/*
 * KEY LEARNINGS:
 * 1. Integer overflow wraps around silently in C++
 * 2. Always check for overflow before arithmetic operations
 * 3. Use wider types (long long) for intermediate calculations
 * 4. Built-in functions like __builtin_add_overflow can detect overflow
 * 5. Manual checks: for addition, verify a + b doesn't exceed type limits
 *
 * REAL-WORLD APPLICATION:
 * - Financial calculations (money amounts)
 * - Game scoring systems
 * - Sensor data processing
 * - Any system where accuracy is critical
 */