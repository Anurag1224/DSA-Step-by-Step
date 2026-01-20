// ============================================================================
// PROBLEM 1: Count Digits of a Number
// ============================================================================
//
// Problem Statement:
// Given an integer n, return the number of digits in n.
//
// Examples:
//   Input: n = 12345  → Output: 5
//   Input: n = 0      → Output: 1
//   Input: n = -123   → Output: 3 (ignore sign)
//
// Constraints:
//   -10⁹ ≤ n ≤ 10⁹
//
// ============================================================================

#include <iostream>
#include <cassert>
using namespace std;

// ============================================================================
// APPROACH 1: Brute Force (O(d) where d = number of digits)
// ============================================================================
//
// Thinking:
// - Every time we divide a number by 10, we remove one digit from right
// - Example: 12345 → 1234 → 123 → 12 → 1 → 0
// - Count how many times we can divide until number becomes 0
//
// Edge Cases to Handle:
// 1. n = 0: Zero has 1 digit, but while(n > 0) never runs → handle explicitly
// 2. n < 0: We ignore sign, so convert to positive with abs()
// 3. Single digit: Should return 1 (loop still works correctly)
//
// Time Complexity: O(d) where d = number of digits (d ≈ log₁₀(n))
// Space Complexity: O(1) - only using one variable
//

int countDigits(int n) {
    // EDGE CASE: Handle zero explicitly (zero has 1 digit)
    if (n == 0) {
        return 1;
    }

    // EDGE CASE: Handle negative numbers by taking absolute value
    // (we only care about digit count, not sign)
    n = abs(n);

    // Standard algorithm: divide by 10 each time and count
    int count = 0;

    while (n > 0) {
        // Remove last digit by dividing by 10
        n /= 10;

        // Increment counter for each digit removed
        count++;
    }

    return count;
}

// ============================================================================
// TESTING & VERIFICATION
// ============================================================================

int main() {
    // Test Case 1: Normal positive number
    assert(countDigits(12345) == 5);
    cout << "✓ Test 1 passed: countDigits(12345) = 5\n";

    // Test Case 2: Zero (EDGE CASE)
    assert(countDigits(0) == 1);
    cout << "✓ Test 2 passed: countDigits(0) = 1\n";

    // Test Case 3: Single digit positive number
    assert(countDigits(5) == 1);
    cout << "✓ Test 3 passed: countDigits(5) = 1\n";

    // Test Case 4: Negative number (EDGE CASE)
    assert(countDigits(-123) == 3);
    cout << "✓ Test 4 passed: countDigits(-123) = 3\n";

    // Test Case 5: Large number
    assert(countDigits(999999999) == 9);
    cout << "✓ Test 5 passed: countDigits(999999999) = 9\n";

    // Test Case 6: Negative single digit (EDGE CASE)
    assert(countDigits(-5) == 1);
    cout << "✓ Test 6 passed: countDigits(-5) = 1\n";

    cout << "\n✅ All tests passed!\n";
    return 0;
}

// ============================================================================
// COMPLEXITY ANALYSIS
// ============================================================================
//
// Time Complexity: O(d) where d = number of digits
//   - Loop runs exactly d times (where d = floor(log₁₀(n)) + 1)
//   - Each iteration does constant work (divide, count++)
//   - For n = 10⁹, d ≈ 10, so very fast
//
// Space Complexity: O(1)
//   - Only using one integer variable `count`
//   - Not dependent on input size
//   - No recursion, no extra arrays
//

// ============================================================================
// REAL-WORLD APPLICATIONS
// ============================================================================
//
// 1. PHONE NUMBER VALIDATION
//    ✓ Validate that phone number has exactly 10 digits
//
// 2. ID GENERATION
//    ✓ Generate IDs with specific length
//    ✓ Mask sensitive numbers by checking length
//
// 3. NUMERIC FORMATTING
//    ✓ Format numbers with leading zeros
//    ✓ Right-align numbers in display
//
// 4. FINANCIAL CALCULATIONS
//    ✓ Validate account numbers
//    ✓ Check transaction amounts have reasonable precision
//
// Example (Phone Validation):
//   if (countDigits(phoneNumber) != 10) {
//       throw InvalidPhoneNumber();
//   }
//   // Valid only if has exactly 10 digits
//

// ============================================================================
// HOW THIS BREAKS IN PRODUCTION
// ============================================================================
//
// ❌ Problem: Forgetting n = 0 case
//   if (n = 0) return 1;    // WRONG SYNTAX: = is assignment, not comparison!
//   if (n == 0) return 1;   // CORRECT SYNTAX: == is comparison
//
// ❌ Problem: Not handling negatives
//   countDigits(-123) → enters infinite loop or wrong answer
//   → validation systems reject valid inputs
//   → users locked out of accounts
//
// ❌ Problem: Integer overflow (for large numbers)
//   // If we were multiplying instead of dividing, we could overflow
//   int result = n * 10;  // could overflow!
//
// ✅ Solution: Explicit edge case handling + clear logic
//

// ============================================================================
// VARIATIONS & SIMILAR PROBLEMS
// ============================================================================
//
// 1. Count digits with custom base (binary, hex, etc.)
//    Solution: Change division from /10 to /base
//
// 2. Sum of digits
//    Solution: Use (n % 10) instead of just dividing
//
// 3. Product of digits
//    Solution: Multiply (n % 10) each iteration
//
// 4. Check if palindrome of digits
//    Solution: Reverse the number, compare
//

// ============================================================================
