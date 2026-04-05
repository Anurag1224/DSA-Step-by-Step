#include <bits/stdc++.h>
using namespace std;

/*
 * PROBLEM: Large Factorial Modulo
 *
 * Compute N! % MOD for large N (up to 10^6) efficiently.
 * Direct computation would overflow, so we use modulo at each step.
 *
 * TIME COMPLEXITY: O(N)
 * SPACE COMPLEXITY: O(1)
 *
 * KEY CONCEPTS:
 * - Factorial grows extremely fast: 20! already exceeds 64-bit integers
 * - Modular arithmetic: (a*b) % MOD = ((a%MOD) * (b%MOD)) % MOD
 * - We can compute factorial modulo MOD by taking modulo at each multiplication
 * - This works because (a*b*c) % MOD = ((a*b)%MOD * c) % MOD
 */

class FactorialModulo {
public:
    // Method 1: Iterative factorial with modulo
    static long long factorialModulo_iterative(long long n, long long mod) {
        if (n < 0) return 0;  // Factorial undefined for negative numbers
        if (n == 0 || n == 1) return 1;

        long long result = 1;

        for (long long i = 2; i <= n; i++) {
            result = (result * i) % mod;

            // Early termination if result becomes 0
            // This happens when MOD divides the factorial
            if (result == 0) break;
        }

        return result;
    }

    // Method 2: Using vector to store intermediate results (for analysis)
    static long long factorialModulo_with_tracking(long long n, long long mod, vector<long long>& intermediate) {
        if (n < 0) return 0;
        if (n == 0 || n == 1) {
            intermediate = {1};
            return 1;
        }

        long long result = 1;
        intermediate.push_back(1);  // 1! = 1

        for (long long i = 2; i <= n; i++) {
            result = (result * i) % mod;
            intermediate.push_back(result);

            if (result == 0) break;
        }

        return result;
    }

    // Method 3: Optimized for when we know factorial will be 0
    static bool willFactorialBeZero(long long n, long long mod) {
        // If MOD <= N, then MOD is a factor of N!, so N! % MOD = 0
        return mod <= n;
    }
};

int main() {
    cout << "=== Large Factorial Modulo Demonstration ===\n\n";

    // Test cases: {N, MOD}
    vector<pair<long long, long long>> testCases = {
        {5, 1000000007},      // Small N
        {10, 13},             // N > MOD
        {20, 1000000007},     // Larger N
        {100, 1000000007},    // Much larger N
        {13, 13},             // N = MOD (should be 0)
        {14, 13},             // N > MOD (should be 0)
        {1000000, 1000000007} // Very large N
    };

    for (auto& test : testCases) {
        long long n = test.first, mod = test.second;

        cout << "Computing: " << n << "! % " << mod << "\n";

        // Check if result will be 0
        bool willBeZero = FactorialModulo::willFactorialBeZero(n, mod);
        cout << "  Will be zero: " << (willBeZero ? "Yes" : "No") << "\n";

        // Compute factorial modulo
        auto start = chrono::high_resolution_clock::now();
        long long result = FactorialModulo::factorialModulo_iterative(n, mod);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

        cout << "  Result: " << result << " (Time: " << duration.count() << " μs)\n";

        // For small N, show intermediate steps
        if (n <= 15) {
            vector<long long> intermediate;
            long long result_with_tracking = FactorialModulo::factorialModulo_with_tracking(n, mod, intermediate);

            cout << "  Intermediate steps:\n";
            for (long long i = 1; i <= n && i < intermediate.size(); i++) {
                cout << "    " << i << "! % " << mod << " = " << intermediate[i] << "\n";
            }
        }

        cout << "\n";
    }

    // Demonstrate factorial growth
    cout << "=== Factorial Growth Demonstration ===\n";
    cout << "Factorial values (showing how quickly they grow):\n";

    vector<long long> small_factorials;
    long long fact = 1;
    for (long long i = 1; i <= 20; i++) {
        fact *= i;
        small_factorials.push_back(fact);
        cout << i << "! = " << fact;
        if (fact > LLONG_MAX / (i + 1)) {
            cout << " (Next multiplication would overflow!)";
        }
        cout << "\n";
    }
    cout << "\n";

    // Show why modulo is necessary
    cout << "=== Why Modulo is Necessary ===\n";
    cout << "Without modulo, 20! would be: " << small_factorials.back() << "\n";
    cout << "With modulo 1000000007: " << (small_factorials.back() % 1000000007) << "\n";
    cout << "Our function computes this efficiently for large N.\n\n";

    return 0;
}

/*
 * KEY LEARNINGS:
 * 1. Factorial grows faster than exponential functions
 * 2. Taking modulo at each step prevents overflow
 * 3. If MOD <= N, then N! is divisible by MOD, so N! % MOD = 0
 * 4. We can stop computation early when result becomes 0
 * 5. Time complexity is O(N), but acceptable for N up to 10^6
 *
 * REAL-WORLD APPLICATIONS:
 * - Combinatorics problems (permutations, combinations)
 * - Probability calculations
 * - Statistical computations
 * - Competitive programming (many problems require N!)
 * - Number theory (Wilson's theorem, etc.)
 */