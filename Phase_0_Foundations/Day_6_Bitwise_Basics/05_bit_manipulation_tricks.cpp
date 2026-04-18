#include <bits/stdc++.h>
using namespace std;

/*
Problem: Bit Manipulation Tricks
Common bit manipulation techniques and optimizations.

Time: O(1) for most operations
Space: O(1)

KEY CONCEPT:
- Bit tricks replace arithmetic operations
- Often faster and more elegant
- Essential for competitive programming
*/

class BitTricks {
public:
    // Check if number is even or odd (without modulo)
    bool isEven(int n) {
        return (n & 1) == 0;
    }

    // Multiply by 2^k (faster than multiplication)
    int multiplyByPowerOfTwo(int n, int k) {
        return n << k;
    }

    // Divide by 2^k (for positive numbers, faster than division)
    int divideByPowerOfTwo(int n, int k) {
        return n >> k;
    }

    // Check if nth bit is set
    bool isNthBitSet(int num, int n) {
        return (num & (1 << n)) != 0;
    }

    // Set nth bit to 1
    int setNthBit(int num, int n) {
        return num | (1 << n);
    }

    // Clear nth bit to 0
    int clearNthBit(int num, int n) {
        return num & ~(1 << n);
    }

    // Toggle nth bit
    int toggleNthBit(int num, int n) {
        return num ^ (1 << n);
    }

    // Get lowest set bit
    int getLowestSetBit(int n) {
        return n & -n;  // Two's complement trick
    }

    // Clear lowest set bit
    int clearLowestSetBit(int n) {
        return n & (n - 1);
    }

    // Check if power of 4 (must be power of 2 and odd position)
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        // Must be power of 2 AND (n & 0xAAAAAAAA) == 0 (even positions only)
        return (n & (n - 1)) == 0 && (n & 0xAAAAAAAA) == 0;
    }

    // Swap two numbers without temp variable
    pair<int, int> swapWithoutTemp(int a, int b) {
        a ^= b;
        b ^= a;
        a ^= b;
        return {a, b};
    }

    // Count number of bits needed to convert A to B
    int bitsToConvert(int a, int b) {
        int xor_result = a ^ b;
        int count = 0;
        while (xor_result) {
            count += xor_result & 1;
            xor_result >>= 1;
        }
        return count;
    }

    // Reverse bits of a number
    int reverseBits(int n) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            result = (result << 1) | (n & 1);
            n >>= 1;
        }
        return result;
    }

    // Check if two numbers have opposite signs
    bool haveOppositeSigns(int a, int b) {
        return (a ^ b) < 0;  // XOR of signs gives negative if different
    }

    // Absolute value without branching
    int absoluteValue(int n) {
        int mask = n >> 31;  // All 1s if negative, all 0s if positive
        return (n ^ mask) - mask;
    }

    // Find minimum without branching
    int minimum(int a, int b) {
        int diff = a - b;
        int mask = diff >> 31;  // All 1s if a < b, all 0s if a >= b
        return b + (diff & mask);
    }

    // Check if number is power of 2 (already seen, but good recap)
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }

    // Find position of highest set bit
    int highestSetBitPosition(int n) {
        if (n == 0) return -1;

        int position = 0;
        while (n >>= 1) position++;
        return position;
    }
};

/*
KEY LEARNINGS:
1. n & 1 checks parity (even/odd)
2. << and >> for fast multiply/divide by powers of 2
3. n & -n isolates lowest set bit
4. n & (n-1) clears lowest set bit
5. XOR tricks: swap, find differences, opposite signs
6. Bit masks for conditional operations without branching

TRICK EXAMPLES:
- Absolute value: (n ^ mask) - mask where mask = n >> 31
- Minimum: b + (diff & mask) where mask = (a-b) >> 31
- Opposite signs: (a ^ b) < 0

PERFORMANCE BENEFITS:
- No branching in some cases (better for CPU pipelining)
- Single CPU instructions for bit operations
- Memory efficient (pack multiple flags)

REAL-WORLD APPLICATIONS:
- Game engines (collision detection, state flags)
- Network protocols (bit fields in packets)
- Embedded systems (memory constraints)
- Cryptography (bit-level operations)
- Graphics programming (pixel manipulation)
*/