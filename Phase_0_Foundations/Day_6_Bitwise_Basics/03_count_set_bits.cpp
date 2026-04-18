#include <bits/stdc++.h>
using namespace std;

/*
Problem: Count Set Bits (Hamming Weight)
Count the number of 1s in binary representation of a number.

Time: O(log n) for naive, O(number of set bits) for optimized
Space: O(1)

KEY CONCEPT:
- Also called "population count" or "Hamming weight"
- Used in many algorithms and data compression
*/

class BitCounter {
public:
    // Method 1: Naive approach - check each bit
    int countBits_naive(int n) {
        int count = 0;
        while (n > 0) {
            if (n & 1) count++;  // Check LSB
            n >>= 1;             // Shift right
        }
        return count;
    }

    // Method 2: Brian Kernighan algorithm (most efficient)
    int countBits_kernighan(int n) {
        int count = 0;
        while (n > 0) {
            n &= n - 1;  // Clear lowest set bit
            count++;
        }
        return count;
    }

    // Method 3: Using built-in function (if available)
    int countBits_builtin(int n) {
        return __builtin_popcount(n);
    }

    // Method 4: Lookup table approach (for 32-bit numbers)
    int countBits_lookup(int n) {
        // Precomputed lookup table for 8-bit values
        static const int lookup[256] = {
            0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
            1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
            1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
            2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
            1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
            2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
            2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
            3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
            1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
            2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
            2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
            3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
            2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
            3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
            3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
            4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8
        };

        return lookup[n & 0xFF] +
               lookup[(n >> 8) & 0xFF] +
               lookup[(n >> 16) & 0xFF] +
               lookup[(n >> 24) & 0xFF];
    }

    // Count bits in range [0, position]
    int countBitsUpToPosition(int n, int position) {
        int count = 0;
        for (int i = 0; i <= position; i++) {
            if (n & (1 << i)) count++;
        }
        return count;
    }

    // Get the position of the highest set bit
    int highestSetBitPosition(int n) {
        if (n == 0) return -1;

        int position = 0;
        while (n > 1) {
            n >>= 1;
            position++;
        }
        return position;
    }
};

/*
KEY LEARNINGS:
1. Brian Kernighan: n &= n-1 clears lowest set bit
2. Each iteration counts one set bit
3. O(number of set bits) vs O(log n) for naive
4. Built-in __builtin_popcount is fastest
5. Lookup tables for repeated use

EXAMPLES:
- 13: 1101 → 3 set bits
- 16: 10000 → 1 set bit
- 31: 11111 → 5 set bits

REAL-WORLD APPLICATIONS:
- Population count in genetic algorithms
- Hamming distance calculations
- Bit manipulation in compression
- Hardware instruction counting
*/