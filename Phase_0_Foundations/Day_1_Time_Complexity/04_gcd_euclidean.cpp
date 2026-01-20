// ============================================================================
// PROBLEM 4: GCD (Greatest Common Divisor) - Euclidean Algorithm
// ============================================================================
//
// Problem Statement:
// Find the greatest common divisor (GCD) of two integers a and b.
// GCD is the largest positive integer that divides both a and b evenly.
//
// Examples:
//   Input: a = 24, b = 36  → Output: 12
//   Input: a = 5, b = 10   → Output: 5
//   Input: a = 7, b = 13   → Output: 1 (coprime)
//   Input: a = 0, b = 5    → Output: 5
//
// Constraints:
//   -10⁹ ≤ a, b ≤ 10⁹
//
// Note: We use Euclidean Algorithm for O(log n) efficiency
//
// ============================================================================

#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

// ============================================================================
// UNDERSTANDING GCD
// ============================================================================
//
// What is GCD?
// Largest number that divides both a and b with remainder 0.
//
// Example: gcd(24, 36)
//   Divisors of 24: 1, 2, 3, 4, 6, 8, 12, 24
//   Divisors of 36: 1, 2, 3, 4, 6, 9, 12, 18, 36
//   Common: 1, 2, 3, 4, 6, 12
//   Greatest: 12 → GCD = 12
//
// Why is this important?
// - Reducing fractions: 24/36 = (24/12)/(36/12) = 2/3
// - Finding common scales in design
// - Cryptography and number theory
// - Load balancing algorithms
// - Memory optimization
//

// ============================================================================
// APPROACH 1: BRUTE FORCE (Not recommended)
// ============================================================================
//
// int gcdBruteForce(int a, int b) {
//     int result = 1;
//     // Check every number from 1 to min(a, b)
//     for (int i = 1; i <= min(abs(a), abs(b)); i++) {
//         if (a % i == 0 && b % i == 0) {
//             result = i;  // Keep updating to largest found
//         }
//     }
//     return result;
// }
//
// Time Complexity: O(n) - could check million times!
// Space Complexity: O(1)
//
// This is SLOW for large numbers. We can do much better!
//

// ============================================================================
// APPROACH 2: EUCLIDEAN ALGORITHM (Optimal! ⭐)
// ============================================================================
//
// KEY INSIGHT (Mathematical Fact):
// gcd(a, b) = gcd(b, a % b)
//
// WHY THIS WORKS:
// If we write a = b*q + r (where r = a % b)
// Any number dividing both a and b must also divide r
// (because r = a - b*q, and if d divides both a and b, then d divides r)
// So common divisors of (a,b) are exactly the common divisors of (b,r)
//
// EXAMPLE: gcd(24, 36)
// Step 1: gcd(24, 36) = gcd(36, 24%36) = gcd(36, 24)
// Step 2: gcd(36, 24) = gcd(24, 36%24) = gcd(24, 12)
// Step 3: gcd(24, 12) = gcd(12, 24%12) = gcd(12, 0)
// Step 4: When b=0, return a (which is 12)
//
// Time Complexity: O(log(min(a,b))) - MUCH faster!
// Space Complexity: O(log(min(a,b))) - recursion stack depth
//

int gcd(int a, int b) {
    // Handle negative numbers by taking absolute values
    a = abs(a);
    b = abs(b);

    // Base case: if b is 0, then a is the GCD
    if (b == 0) {
        return a;
    }

    // Recursive case: gcd(b, a%b)
    return gcd(b, a % b);
}

// ============================================================================
// ITERATIVE VERSION (Saves recursion stack space)
// ============================================================================
//
// int gcdIterative(int a, int b) {
//     a = abs(a);
//     b = abs(b);
//
//     while (b != 0) {
//         int temp = b;
//         b = a % b;
//         a = temp;
//     }
//
//     return a;
// }
//
// Same time complexity: O(log n)
// Better space complexity: O(1) instead of O(log n)
//
// Advantage: No recursion overhead, no stack depth limit
// Disadvantage: Slightly less elegant code
//

// ============================================================================
// TESTING & VERIFICATION
// ============================================================================

int main() {
    // Test Case 1: Classic example from problem
    assert(gcd(24, 36) == 12);
    cout << "✓ Test 1 passed: gcd(24, 36) = 12\n";

    // Test Case 2: One divides the other
    assert(gcd(5, 10) == 5);
    cout << "✓ Test 2 passed: gcd(5, 10) = 5\n";

    // Test Case 3: Coprime numbers (GCD = 1)
    assert(gcd(7, 13) == 1);
    cout << "✓ Test 3 passed: gcd(7, 13) = 1\n";

    // Test Case 4: One number is zero (EDGE CASE)
    assert(gcd(0, 5) == 5);
    cout << "✓ Test 4 passed: gcd(0, 5) = 5\n";

    // Test Case 5: Both numbers are zero (EDGE CASE)
    assert(gcd(0, 0) == 0);
    cout << "✓ Test 5 passed: gcd(0, 0) = 0\n";

    // Test Case 6: Negative numbers (EDGE CASE)
    assert(gcd(-24, 36) == 12);
    cout << "✓ Test 6 passed: gcd(-24, 36) = 12\n";

    // Test Case 7: Both negative (EDGE CASE)
    assert(gcd(-24, -36) == 12);
    cout << "✓ Test 7 passed: gcd(-24, -36) = 12\n";

    // Test Case 8: Same number
    assert(gcd(5, 5) == 5);
    cout << "✓ Test 8 passed: gcd(5, 5) = 5\n";

    // Test Case 9: Consecutive Fibonacci-like numbers (worst case for Euclidean)
    assert(gcd(21, 13) == 1);
    cout << "✓ Test 9 passed: gcd(21, 13) = 1\n";

    // Test Case 10: Large numbers (still fast!)
    assert(gcd(1000000000, 999999999) == 1);
    cout << "✓ Test 10 passed: gcd(1000000000, 999999999) = 1\n";

    cout << "\n✅ All tests passed!\n";
    return 0;
}

// ============================================================================
// COMPLEXITY ANALYSIS
// ============================================================================
//
// Time Complexity: O(log(min(a,b)))
//   - Each step: b becomes a%b, which is < b/2
//   - Reduces b by at least half each iteration
//   - Number of steps ≈ log₂(min(a,b))
//   - For a=10⁹: only ~30 steps!
//
// Space Complexity: O(log(min(a,b))) [recursive version]
//   - Call stack depth = O(log n)
//   - Each recursive call adds to stack
//   - Maximum depth is limited by log complexity
//
// Space Complexity: O(1) [iterative version]
//   - Only using temporary variables
//   - No extra data structures
//   - Preferred in production!
//

// ============================================================================
// REAL-WORLD APPLICATIONS
// ============================================================================
//
// 1. FRACTION REDUCTION
//    ✓ Simplify 24/36 to 2/3
//    ✓ Used in: financial calculations, graphics, physics simulations
//
//    Example:
//    int numerator = 24, denominator = 36;
//    int g = gcd(numerator, denominator);
//    numerator /= g;        // 2
//    denominator /= g;      // 3
//
// 2. CRYPTOGRAPHY (RSA Algorithm)
//    ✓ Find coprime numbers (gcd = 1)
//    ✓ Key generation depends on GCD properties
//    ✓ Wrong GCD handling breaks encryption
//
// 3. LOAD BALANCING IN DISTRIBUTED SYSTEMS
//    ✓ Distribute tasks across servers optimally
//    ✓ Ensure even distribution using GCD properties
//    ✓ Prevent hotspots where some servers are overloaded
//
// 4. MEMORY ALIGNMENT
//    ✓ Align data in memory for efficient access
//    ✓ GCD determines optimal block size
//    ✓ CPU cache optimization
//
// 5. NETWORK PACKET SIZING
//    ✓ Find common denominator for packet sizes
//    ✓ Optimize transmission rates
//    ✓ Minimize wasted bandwidth
//
// 6. MUSIC THEORY (Harmony & Frequency)
//    ✓ Find harmonic relationship between frequencies
//    ✓ gcd determines beat frequency
//    ✓ Used in audio engineering
//

// ============================================================================
// HOW THIS BREAKS IN PRODUCTION
// ============================================================================
//
// ❌ Problem: Not handling negatives
//   gcd(-24, 36) with modulo operator behavior varies by language
//   (-24) % 36 could be -24 or 12 depending on language
//   → cryptography security breaks
//   → load balancing fails
//
// ❌ Problem: Using brute force on large numbers
//   gcd(10^9, 10^9 - 1) with brute force: O(10^9) operations
//   → API timeout
//   → system lag
//   → customer complaints
//
// ❌ Problem: Deep recursion (stack overflow)
//   In iterative systems with shallow stack limits
//   → program crashes
//   → partial data loss
//   // Solution: Use iterative version instead
//
// ❌ Problem: Not handling zero cases
//   If system assumes both numbers are non-zero
//   → crash on edge cases
//   → hidden bugs that only appear in production
//
// ✅ Solution: Euclidean algorithm + explicit edge case handling
//

// ============================================================================
// VARIATIONS & SIMILAR PROBLEMS
// ============================================================================
//
// 1. LCM (Least Common Multiple)
//    Solution: lcm(a,b) = (a * b) / gcd(a,b)
//
// 2. GCD of Multiple Numbers
//    Solution: gcd(a,b,c) = gcd(gcd(a,b), c)
//
// 3. Extended Euclidean Algorithm
//    Solution: Find x,y such that ax + by = gcd(a,b)
//    Used in: cryptography, solving linear Diophantine equations
//
// 4. Find GCD with Modular Arithmetic
//    Solution: gcd(a % m, b) = gcd(a, b)
//

// ============================================================================
// LEARNING POINTS TO REMEMBER
// ============================================================================
//
// 1. Mathematical insight (gcd(a,b) = gcd(b, a%b)) leads to O(log n)
// 2. Not all algorithms need to be memorized - understand WHY they work
// 3. Edge cases (zero, negative) are not afterthoughts - handle explicitly
// 4. Iterative > Recursive when recursion depth concerns you
// 5. Real-world: Wrong GCD algorithm can crash cryptography!
//

// ============================================================================
