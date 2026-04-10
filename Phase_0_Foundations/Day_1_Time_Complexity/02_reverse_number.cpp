// ============================================================================
// PROBLEM 2: Reverse a Number
// ============================================================================
//
// Problem Statement:
// Given an integer n, reverse its digits. If reversing causes overflow,
// return the number as-is (or handle gracefully).
//
// Examples:
//   Input: n = 1234  → Output: 4321
//   Input: n = 1200  → Output: 21 (leading zeros are dropped)
//   Input: n = 0     → Output: 0
//   Input: n = -123  → Output: -321 (preserve sign)
//
// Constraints:
//   -10⁹ ≤ n ≤ 10⁹
//
// ============================================================================

#include <iostream>
#include <cassert>
#include <climits>
using namespace std;

// ============================================================================
// APPROACH: Extract digits one by one and build reversed number
// ============================================================================
//
// Thinking:
// - Last digit becomes first: use modulo (%)
// - Shift previous reversed: multiply by 10
// - Example: reverse 123
//   Step 1: digit = 3, reversed = 0*10 + 3 = 3
//   Step 2: digit = 2, reversed = 3*10 + 2 = 32
//   Step 3: digit = 1, reversed = 32*10 + 1 = 321
//
// Edge Cases to Handle:
// 1. n = 0: Already reversed, return 0
// 2. n < 0: Store sign, reverse absolute, reapply sign
// 3. Leading zeros: Automatically handled (10*... drops zeros)
// 4. Overflow: Could happen with large numbers (mentioned in problem)
//
// Time Complexity: O(d) where d = number of digits
// Space Complexity: O(1) - only using variables
//

int reverseNumber(int n) {
    // EDGE CASE: Store sign separately (we'll reapply it at end)
    int sign = (n < 0) ? -1 : 1;

    // Convert to positive for processing
    n = abs(n);

    // Build reversed number
    int reversed = 0;

    while (n > 0) {
        // Extract last digit
        int digit = n % 10;

        // Shift reversed left and append digit
        // Example: reversed = 32, digit = 3 → 32*10 + 3 = 323
        reversed = reversed * 10 + digit;

        // Remove last digit from n
        n /= 10;
    }

    // EDGE CASE: Reapply original sign
    return reversed * sign;
}

// ============================================================================
// ALTERNATIVE: Using long long to detect overflow
// ============================================================================
//
// If we need to detect overflow instead of ignoring it:
//
// int reverseNumberWithCheck(int n) {
//     int sign = (n < 0) ? -1 : 1;
//     long long n_abs = abs((long long)n);  // Use long long for safety
//     long long reversed = 0;
//
//     while (n_abs > 0) {
//         int digit = n_abs % 10;
//         reversed = reversed * 10 + digit;
//
           // Check overflow before returning
//         if (reversed > INT_MAX) return 0;  // or handle error
//
//         n_abs /= 10;
//     }
//
//     return (int)(reversed * sign);
// }
//

// ============================================================================
// TESTING & VERIFICATION
// ============================================================================

int main() {
    // Test Case 1: Normal positive number
    assert(reverseNumber(1234) == 4321);
    cout << "✓ Test 1 passed: reverseNumber(1234) = 4321\n";

    // Test Case 2: Number with trailing zeros (becomes leading when reversed)
    assert(reverseNumber(1200) == 21);
    cout << "✓ Test 2 passed: reverseNumber(1200) = 21\n";

    // Test Case 3: Zero
    assert(reverseNumber(0) == 0);
    cout << "✓ Test 3 passed: reverseNumber(0) = 0\n";

    // Test Case 4: Negative number (EDGE CASE)
    assert(reverseNumber(-123) == -321);
    cout << "✓ Test 4 passed: reverseNumber(-123) = -321\n";

    // Test Case 5: Single digit
    assert(reverseNumber(5) == 5);
    cout << "✓ Test 5 passed: reverseNumber(5) = 5\n";

    // Test Case 6: Number with all trailing zeros except first digit
    assert(reverseNumber(100) == 1);
    cout << "✓ Test 6 passed: reverseNumber(100) = 1\n";

    // Test Case 7: Large negative number
    assert(reverseNumber(-98765) == -56789);
    cout << "✓ Test 7 passed: reverseNumber(-98765) = -56789\n";

    cout << "\n✅ All tests passed!\n";
    return 0;
}

// ============================================================================
// COMPLEXITY ANALYSIS
// ============================================================================
//
// Time Complexity: O(d) where d = number of digits
//   - Loop runs d times (d = floor(log₁₀(n)) + 1)
//   - Each iteration: modulo, divide, multiply (all O(1) on integers)
//   - Total: O(d) which is O(log n) for n as numeric value
//
// Space Complexity: O(1)
//   - Only using constant extra variables (sign, digit, reversed)
//   - Not scaling with input
//   - No recursion
//

// ============================================================================
// REAL-WORLD APPLICATIONS
// ============================================================================
//
// 1. TRANSACTION ID OBFUSCATION
//    ✓ Reverse internal IDs before displaying to users
//    ✓ Prevents users from guessing next transaction ID
//
// 2. DATA INTEGRITY CHECKS
//    ✓ Some systems reverse numbers for checksums
//    ✓ Example: ISBN calculation
//
// 3. MIRRORING IN UI
//    ✓ Display numbers in reversed order
//    ✓ Mirror identifiers in logs
//
// 4. BIDIRECTIONAL ENCODING
//    ✓ Use reversal as lightweight encryption
//    ✓ Check if data matches expected patterns
//
// Example (Transaction ID obfuscation):
//   int internalId = 12345;
//   int publicId = reverseNumber(internalId);  // 54321
     // Store publicId in database
     // When user references it, reverse back:
//   int recovered = reverseNumber(publicId);  // 12345
//

// ============================================================================
// HOW THIS BREAKS IN PRODUCTION
// ============================================================================
//
// ❌ Problem: Not initializing reversed variable
//   int reversed;  // uninitialized!
//   reversed = reversed * 10 + digit;  // garbage value * 10 + digit
     // Results in unpredictable values
//
// ❌ Problem: Forgetting negative handling
//   reverseNumber(-123) → treats as 123, reverses to 321
//   → loses negative sign
//   → wrong data stored
//
// ❌ Problem: Not handling trailing zeros
//   reverseNumber(1200) → 21 (correct due to algorithm)
     // But if you manually reverse: "0021" → leading zeros
     // Must understand this automatically handled by integer arithmetic
//
// ❌ Problem: Integer overflow in reversal
//   If number is near INT_MAX, reversing could overflow
//   Solution: Use long long for intermediate calculation
//
// ✅ Solution: Explicit handling + understanding of edge cases
//

// ============================================================================
// VARIATIONS & SIMILAR PROBLEMS
// ============================================================================
//
// 1. Palindrome Number
//    Solution: Reverse and compare with original
//
// 2. Reverse String (similar logic, different data type)
//    Solution: Use two pointers, swap from outside in
//
// 3. Reverse Only Digits (keep non-digits in place)
//    Solution: Filter digits, reverse, insert back
//
// 4. Reverse Number with Modulo (prevent overflow)
//    Solution: Use modulo arithmetic: (reversed * 10 + digit) % MOD
//

// ============================================================================
