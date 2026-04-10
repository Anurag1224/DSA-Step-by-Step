// ============================================================================
// PROBLEM 3: Palindrome Number
// ============================================================================
//
// Problem Statement:
// Given an integer n, return true if n is a palindrome, false otherwise.
// Negative numbers are NOT palindromes.
//
// Examples:
//   Input: n = 121   → Output: true
//   Input: n = -121  → Output: false (negative)
//   Input: n = 0     → Output: true
//   Input: n = 10    → Output: false (01 ≠ 10)
//
// Constraints:
//   -10⁹ ≤ n ≤ 10⁹
//
// Definition: A palindrome reads the same forwards and backwards
//
// ============================================================================

#include <iostream>
#include <cassert>
using namespace std;

// ============================================================================
// HELPER FUNCTION: Reverse a Number (from Problem 2)
// ============================================================================
//
// We reuse the reverseNumber function because palindrome check is:
// "Does the number equal its reverse?"
//

int reverseNumber(int n) {
    int sign = (n < 0) ? -1 : 1;
    n = abs(n);

    int reversed = 0;

    while (n > 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }

    return reversed * sign;
}

// ============================================================================
// APPROACH: Reverse and Compare
// ============================================================================
//
// Thinking:
// - Negative numbers have minus sign, so "mirror" doesn't make sense
// - For positive (and zero), reverse it
// - If original == reversed, it's a palindrome
//
// Example: 121
//   original = 121
//   reversed = reverseNumber(121) = 121
//   121 == 121 → true
//
// Example: 123
//   original = 123
//   reversed = reverseNumber(123) = 321
//   123 ≠ 321 → false
//
// Edge Cases to Handle:
// 1. n < 0: Negative numbers are never palindromes (return false immediately)
// 2. n = 0: Single digit, always palindrome
// 3. Single digit positive: Always palindrome (mirrors itself)
//
// Time Complexity: O(d) where d = number of digits
// Space Complexity: O(1)
//

bool isPalindrome(int n) {
    // EDGE CASE: Negative numbers are not palindromes
    // (The minus sign breaks symmetry)
    if (n < 0) {
        return false;
    }

    // Store original for comparison
    int original = n;

    // Reverse the number
    int reversed = reverseNumber(n);

    // Palindrome if original equals its reverse
    return original == reversed;
}

// ============================================================================
// ALTERNATIVE APPROACH: Two Pointers (Without Reversing)
// ============================================================================
//
// We could also compare digits from both ends without fully reversing:
//
// bool isPalindromeAlt(int n) {
//     if (n < 0) return false;
       // Convert to string for easy digit access
//     string s = to_string(n);
//
//     int left = 0;
//     int right = s.length() - 1;
//
//     while (left < right) {
//         if (s[left] != s[right]) {
//             return false;
//         }
//         left++;
//         right--;
//     }
//     return true;
// }
//
// This avoids building reversed number, but uses string space O(d)
// Original approach is slightly better in space.
//

// ============================================================================
// TESTING & VERIFICATION
// ============================================================================

int main() {
    // Test Case 1: Classic palindrome
    assert(isPalindrome(121) == true);
    cout << "✓ Test 1 passed: isPalindrome(121) = true\n";

    // Test Case 2: Not a palindrome
    assert(isPalindrome(123) == false);
    cout << "✓ Test 2 passed: isPalindrome(123) = false\n";

    // Test Case 3: Negative number (EDGE CASE)
    assert(isPalindrome(-121) == false);
    cout << "✓ Test 3 passed: isPalindrome(-121) = false\n";

    // Test Case 4: Zero
    assert(isPalindrome(0) == true);
    cout << "✓ Test 4 passed: isPalindrome(0) = true\n";

    // Test Case 5: Single digit
    assert(isPalindrome(7) == true);
    cout << "✓ Test 5 passed: isPalindrome(7) = true\n";

    // Test Case 6: Two-digit palindrome
    assert(isPalindrome(11) == true);
    cout << "✓ Test 6 passed: isPalindrome(11) = true\n";

    // Test Case 7: Two-digit non-palindrome
    assert(isPalindrome(10) == false);
    cout << "✓ Test 7 passed: isPalindrome(10) = false\n";

    // Test Case 8: Large palindrome
    assert(isPalindrome(12321) == true);
    cout << "✓ Test 8 passed: isPalindrome(12321) = true\n";

    // Test Case 9: Number with trailing zeros (becomes leading when reversed)
    assert(isPalindrome(1001) == true);
    cout << "✓ Test 9 passed: isPalindrome(1001) = true\n";

    cout << "\n✅ All tests passed!\n";
    return 0;
}

// ============================================================================
// COMPLEXITY ANALYSIS
// ============================================================================
//
// Time Complexity: O(d) where d = number of digits
//   - Calls reverseNumber(): O(d)
//   - Then does one comparison: O(1)
//   - Total: O(d)
//
// Space Complexity: O(1)
//   - Only using variables for comparison
//   - Reversal is done in-place (no array)
//   - No recursion beyond reverseNumber (which is also O(1) space)
//

// ============================================================================
// REAL-WORLD APPLICATIONS
// ============================================================================
//
// 1. DATA INTEGRITY CHECKS (Checksums & Validation)
//    ✓ Used in payment card validation algorithms
//    ✓ Verify bank account numbers
//    ✓ Check transaction IDs for tampering
//
// 2. PATTERN MATCHING IN STREAMS
//    ✓ Detect symmetric patterns in sensor data
//    ✓ Identify suspicious transaction sequences
//    ✓ Anomaly detection in logs
//
// 3. DNA SEQUENCE ANALYSIS
//    ✓ Check if sequence reads same in both directions
//    ✓ Identify palindromic sequences (biological importance)
//
// 4. FRAUD DETECTION
//    ✓ Suspicious patterns often break symmetry
//    ✓ Legitimate transactions often have certain symmetry properties
//
// Example (Payment Card Validation):
     // Some credit cards have palindrome properties in certain fields
//   if (isPalindrome(cardNumber)) {
         // Additional verification might be needed
//       performExtraChecks();
//   }
//

// ============================================================================
// HOW THIS BREAKS IN PRODUCTION
// ============================================================================
//
// ❌ Problem: Forgetting negative check
//   bool wrong = (n == reverseNumber(n));  // -121 would check fine!
     // But mathematically, -121 reversed is -121, so would return true
     // Yet -121 should NOT be palindrome (sign matter)
//   → validation fails silently
//   → fraudulent IDs might pass checks
//
// ❌ Problem: Integer overflow in reversal
//   reverseNumber(n) could overflow if n is very large
//   → wrong comparison result
//   → data corruption
//
// ❌ Problem: Using only string comparison (inefficient)
//   string s = to_string(n);  // extra O(d) space
     // Better to use reversal approach (no extra space)
//
// ✅ Solution: Explicit negative handling + overflow-safe reversal
//

// ============================================================================
// VARIATIONS & SIMILAR PROBLEMS
// ============================================================================
//
// 1. Palindrome String
//    Solution: Two pointers from both ends, compare
//
// 2. Valid Palindrome (ignore non-alphanumeric)
//    Solution: Skip non-alphanumeric during comparison
//
// 3. Almost Palindrome (can remove one character)
//    Solution: Two pointers, try removing from each end when mismatch
//
// 4. Longest Palindromic Substring
//    Solution: Expand from center or dynamic programming
//

// ============================================================================
