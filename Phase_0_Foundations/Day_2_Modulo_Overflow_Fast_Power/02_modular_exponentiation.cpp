#include <bits/stdc++.h>
using namespace std;

/*
 * PROBLEM: Modular Exponentiation (Fast Power)
 *
 * Compute (base^exponent) % modulus efficiently using binary exponentiation.
 * This prevents overflow and runs in O(log exponent) time.
 *
 * TIME COMPLEXITY: O(log exponent)
 * SPACE COMPLEXITY: O(1)
 *
 * KEY CONCEPTS:
 * - Binary exponentiation reduces multiplications
 * - Modular arithmetic: (a*b) % MOD = ((a%MOD) * (b%MOD)) % MOD
 * - Even exponents: (base^2)^(exp/2)
 * - Odd exponents: result * base^(exp-1)
 */

class ModularExponentiation {
public:
    // Method 1: Iterative Binary Exponentiation
    static long long modPow_iterative(long long base, long long exp, long long mod) {
        if (mod == 1) return 0;  // Any number % 1 = 0

        long long result = 1;
        base %= mod;  // Reduce base modulo mod initially

        while (exp > 0) {
            // If exponent is odd, multiply result with base
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }

            // Square the base and reduce exponent by half
            base = (base * base) % mod;
            exp /= 2;
        }

        return result;
    }

    // Method 2: Recursive Binary Exponentiation
    static long long modPow_recursive(long long base, long long exp, long long mod) {
        if (mod == 1) return 0;

        // Base case
        if (exp == 0) return 1;

        // If exponent is even
        if (exp % 2 == 0) {
            long long half = modPow_recursive(base, exp / 2, mod);
            return (half * half) % mod;
        }
        // If exponent is odd
        else {
            long long half = modPow_recursive(base, exp / 2, mod);
            return ((half * half % mod) * (base % mod)) % mod;
        }
    }

    // Method 3: Built-in pow function (for comparison - not recommended for large numbers)
    static long long modPow_builtin(long long base, long long exp, long long mod) {
        // This will overflow for large exponents
        long long result = 1;
        for (long long i = 0; i < exp; i++) {
            result = (result * base) % mod;
        }
        return result;
    }
};

int main() {
    cout << "=== Modular Exponentiation Demonstration ===\n\n";

    // Test cases: {base, exponent, modulus}
    vector<tuple<long long, long long, long long>> testCases = {
        {2, 10, 1000000007},     // 2^10 % MOD
        {3, 5, 13},              // 3^5 % 13
        {7, 0, 100},             // 7^0 % 100 = 1
        {5, 1, 17},              // 5^1 % 17 = 5
        {2, 63, 1000000007},     // Large exponent
        {123456789, 987654321, 1000000007}  // Very large numbers
    };

    for (auto& test : testCases) {
        long long base, exp, mod;
        tie(base, exp, mod) = test;

        cout << "Computing: (" << base << "^" << exp << ") % " << mod << "\n";

        // Iterative method
        auto start_iter = chrono::high_resolution_clock::now();
        long long result_iter = ModularExponentiation::modPow_iterative(base, exp, mod);
        auto end_iter = chrono::high_resolution_clock::now();
        auto duration_iter = chrono::duration_cast<chrono::microseconds>(end_iter - start_iter);

        cout << "  Iterative: " << result_iter << " (Time: " << duration_iter.count() << " μs)\n";

        // Recursive method
        auto start_rec = chrono::high_resolution_clock::now();
        long long result_rec = ModularExponentiation::modPow_recursive(base, exp, mod);
        auto end_rec = chrono::high_resolution_clock::now();
        auto duration_rec = chrono::duration_cast<chrono::microseconds>(end_rec - start_rec);

        cout << "  Recursive: " << result_rec << " (Time: " << duration_rec.count() << " μs)\n";

        // Verify results match
        if (result_iter != result_rec) {
            cout << "  ERROR: Results don't match!\n";
        }

        // For small exponents, compare with naive method
        if (exp <= 20) {
            long long result_naive = ModularExponentiation::modPow_builtin(base, exp, mod);
            cout << "  Naive: " << result_naive;
            if (result_naive != result_iter) {
                cout << " (MISMATCH!)";
            }
            cout << "\n";
        }

        cout << "\n";
    }

    // Demonstrate why fast exponentiation is needed
    cout << "=== Why Fast Exponentiation Matters ===\n";
    cout << "Computing 2^1000 % 1000000007:\n";

    long long base = 2, exp = 1000, mod = 1000000007;

    auto start = chrono::high_resolution_clock::now();
    long long result = ModularExponentiation::modPow_iterative(base, exp, mod);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Result: " << result << "\n";
    cout << "Time taken: " << duration.count() << " microseconds\n";
    cout << "Naive method would take ~1000 multiplications vs ~10 for binary exponentiation\n\n";

    return 0;
}

/*
 * KEY LEARNINGS:
 * 1. Binary exponentiation reduces O(exp) to O(log exp) time
 * 2. Always take modulo at each step to prevent overflow
 * 3. Base case: any number^0 = 1
 * 4. Handle modulus = 1 specially (any number % 1 = 0)
 * 5. Recursive and iterative approaches are equivalent
 *
 * REAL-WORLD APPLICATIONS:
 * - RSA encryption/decryption
 * - Diffie-Hellman key exchange
 * - Hash functions (SHA, MD5)
 * - Cryptographic protocols
 * - Competitive programming problems with large exponents
 */