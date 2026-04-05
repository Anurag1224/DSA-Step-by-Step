#include <bits/stdc++.h>
using namespace std;

/*
 * PROBLEM: Fast Multiplication (Russian Peasant Algorithm)
 *
 * Multiply two large numbers without overflow using bitwise operations.
 * This is an ancient algorithm that uses doubling and halving.
 *
 * TIME COMPLEXITY: O(log b) where b is the smaller number
 * SPACE COMPLEXITY: O(1)
 *
 * KEY CONCEPTS:
 * - Russian peasant multiplication: double one number, halve the other
 * - Add to result when the halved number is odd
 * - Equivalent to binary multiplication
 * - Prevents overflow by avoiding large intermediate results
 */

class FastMultiplication {
public:
    // Method 1: Russian Peasant Multiplication (Iterative)
    static long long russianPeasant_iterative(long long a, long long b) {
        long long result = 0;

        // Make sure a is the smaller number for efficiency
        if (a > b) swap(a, b);

        while (a > 0) {
            // If a is odd, add current b to result
            if (a % 2 == 1) {
                // Check for overflow before adding
                if (result > LLONG_MAX - b) {
                    throw overflow_error("Multiplication result would overflow");
                }
                result += b;
            }

            // Double b, halve a
            b *= 2;
            a /= 2;
        }

        return result;
    }

    // Method 2: Russian Peasant with Modulo
    static long long russianPeasant_modulo(long long a, long long b, long long mod) {
        long long result = 0;
        a %= mod;  // Reduce a modulo mod

        while (b > 0) {
            // If b is odd, add a to result
            if (b % 2 == 1) {
                result = (result + a) % mod;
            }

            // Double a, halve b
            a = (a * 2) % mod;
            b /= 2;
        }

        return result;
    }

    // Method 3: Standard multiplication with overflow check
    static long long standardMultiply_safe(long long a, long long b) {
        // Check for overflow before multiplication
        if (a != 0 && b != 0) {
            if (a > LLONG_MAX / b || (a < LLONG_MIN / b)) {
                throw overflow_error("Multiplication would overflow");
            }
        }

        return a * b;
    }

    // Method 4: Using built-in overflow detection
    static bool builtinMultiply_safe(long long a, long long b, long long& result) {
        return !__builtin_mul_overflow(a, b, &result);
    }
};

int main() {
    cout << "=== Fast Multiplication Demonstration ===\n\n";

    // Test cases: {a, b}
    vector<pair<long long, long long>> testCases = {
        {12, 13},              // 12 * 13 = 156
        {17, 23},              // 17 * 23 = 391
        {1000000, 2000000},    // Large numbers
        {0, 123456789},        // Zero multiplication
        {1, LLONG_MAX},        // Edge case near overflow
        {LLONG_MAX / 2, 2},    // Will overflow with standard multiplication
        {123456789, 987654321} // Very large numbers
    };

    for (auto& test : testCases) {
        long long a = test.first, b = test.second;

        cout << "Multiplying: " << a << " * " << b << "\n";

        // Russian Peasant method
        try {
            auto start_rp = chrono::high_resolution_clock::now();
            long long result_rp = FastMultiplication::russianPeasant_iterative(a, b);
            auto end_rp = chrono::high_resolution_clock::now();
            auto duration_rp = chrono::duration_cast<chrono::nanoseconds>(end_rp - start_rp);

            cout << "  Russian Peasant: " << result_rp << " (Time: " << duration_rp.count() << " ns)\n";
        } catch (const overflow_error& e) {
            cout << "  Russian Peasant: " << e.what() << "\n";
        }

        // Standard multiplication with safety check
        try {
            auto start_std = chrono::high_resolution_clock::now();
            long long result_std = FastMultiplication::standardMultiply_safe(a, b);
            auto end_std = chrono::high_resolution_clock::now();
            auto duration_std = chrono::duration_cast<chrono::nanoseconds>(end_std - start_std);

            cout << "  Standard (safe): " << result_std << " (Time: " << duration_std.count() << " ns)\n";
        } catch (const overflow_error& e) {
            cout << "  Standard (safe): " << e.what() << "\n";
        }

        // Built-in overflow detection
        long long result_builtin;
        bool success_builtin = FastMultiplication::builtinMultiply_safe(a, b, result_builtin);
        cout << "  Built-in check: " << (success_builtin ? to_string(result_builtin) : "Overflow detected") << "\n";

        // For reasonable sizes, show modulo version
        if (a >= 0 && b >= 0 && a <= 1000000000 && b <= 1000000000) {
            long long mod = 1000000007;
            long long result_mod = FastMultiplication::russianPeasant_modulo(a, b, mod);
            cout << "  With modulo " << mod << ": " << result_mod << "\n";
        }

        cout << "\n";
    }

    // Demonstrate the algorithm step by step
    cout << "=== Step-by-Step: Russian Peasant Multiplication ===\n";
    cout << "Computing 27 * 12:\n";
    cout << "Step-by-Step process:\n";

    long long a = 27, b = 12, result = 0;
    cout << "Initial: a = " << a << ", b = " << b << ", result = " << result << "\n";

    int step = 1;
    while (a > 0) {
        cout << "Step " << step << ": ";
        if (a % 2 == 1) {
            cout << "a is odd, add " << b << " to result";
            result += b;
            cout << " → result = " << result;
        } else {
            cout << "a is even, skip addition";
        }
        cout << "\n";

        b *= 2;
        a /= 2;
        cout << "         Double b → " << b << ", halve a → " << a << "\n\n";

        step++;
        if (step > 10) break;  // Prevent infinite loop in case of bug
    }

    cout << "Final result: " << result << " (27 * 12 = " << (27 * 12) << ")\n\n";

    // Performance comparison for large numbers
    cout << "=== Performance Comparison ===\n";
    long long large_a = 1234567890123456789LL;
    long long large_b = 987654321098765432LL;

    cout << "Multiplying two 19-digit numbers:\n";

    // Russian Peasant
    auto start_rp = chrono::high_resolution_clock::now();
    long long rp_result = FastMultiplication::russianPeasant_iterative(large_a, large_b);
    auto end_rp = chrono::high_resolution_clock::now();
    auto rp_duration = chrono::duration_cast<chrono::microseconds>(end_rp - start_rp);

    cout << "Russian Peasant: " << rp_duration.count() << " microseconds\n";
    cout << "Result: " << rp_result << "\n\n";

    return 0;
}

/*
 * KEY LEARNINGS:
 * 1. Russian peasant multiplication uses doubling/halving instead of repeated addition
 * 2. It's equivalent to binary multiplication (each bit position)
 * 3. Prevents overflow by avoiding large intermediate results
 * 4. O(log n) time complexity makes it efficient for large numbers
 * 5. Can be combined with modulo operations for cryptographic applications
 *
 * REAL-WORLD APPLICATIONS:
 * - Multiplying large numbers in systems without big integer support
 * - Cryptographic operations (RSA, ECC)
 * - Embedded systems with limited memory
 * - Ancient calculation methods (still relevant today!)
 * - Competitive programming for overflow-prone problems
 */