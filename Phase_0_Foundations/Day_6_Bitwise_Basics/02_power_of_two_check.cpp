#include <bits/stdc++.h>
using namespace std;

/*
Problem: Check if Number is Power of 2
Determine if a number is a power of 2 using bit manipulation.

Time: O(1)
Space: O(1)

KEY CONCEPT:
- Powers of 2 have exactly one bit set in binary
- n & (n-1) clears the lowest set bit
- For powers of 2: n & (n-1) == 0
*/

class PowerOfTwoChecker {
public:
    // Method 1: Using bit manipulation (most efficient)
    bool isPowerOfTwo_bit(int n) {
        // Handle edge cases
        if (n <= 0) return false;

        // Power of 2 has exactly one bit set
        return (n & (n - 1)) == 0;
    }

    // Method 2: Using loop (educational)
    bool isPowerOfTwo_loop(int n) {
        if (n <= 0) return false;

        // Keep dividing by 2 until we reach 1
        while (n > 1) {
            if (n % 2 != 0) return false;
            n /= 2;
        }
        return true;
    }

    // Method 3: Using logarithm (less efficient, floating point)
    bool isPowerOfTwo_log(int n) {
        if (n <= 0) return false;

        double log_val = log2(n);
        return log_val == (int)log_val;
    }

    // Find the highest power of 2 less than or equal to n
    int highestPowerOfTwo(int n) {
        if (n <= 0) return 0;

        // Set all bits after the highest set bit
        n |= n >> 1;
        n |= n >> 2;
        n |= n >> 4;
        n |= n >> 8;
        n |= n >> 16;

        // Clear all bits except the highest
        return n - (n >> 1);
    }

    // Check if n is power of 2 and find the exponent
    pair<bool, int> isPowerOfTwoWithExponent(int n) {
        if (n <= 0 || (n & (n - 1)) != 0) {
            return {false, -1};
        }

        // Find position of the set bit
        int exponent = 0;
        while (n > 1) {
            n >>= 1;
            exponent++;
        }
        return {true, exponent};
    }
};

/*
KEY LEARNINGS:
1. n & (n-1) trick: Clears lowest set bit
2. Powers of 2: Exactly one bit set
3. Edge cases: 0, negatives are not powers of 2
4. Bit manipulation is O(1), much faster than loops
5. Can find highest power of 2 using bit operations

EXAMPLES:
- 8: 1000 & 0111 = 0000 → Power of 2 (2^3)
- 10: 1010 & 1001 = 1000 → Not power of 2
- 16: 10000 & 01111 = 00000 → Power of 2 (2^4)
*/