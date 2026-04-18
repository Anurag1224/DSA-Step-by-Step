#include <bits/stdc++.h>
using namespace std;

/*
Problem: Bitwise Operations Basics
Learn AND, OR, XOR, and shift operations.

Time: O(1)
Space: O(1)
*/

class BitwiseBasics {
public:
    // Bitwise AND - intersection of bits
    int bitwiseAnd(int a, int b) {
        return a & b;
    }

    // Bitwise OR - union of bits
    int bitwiseOr(int a, int b) {
        return a | b;
    }

    // Bitwise XOR - exclusive OR
    int bitwiseXor(int a, int b) {
        return a ^ b;
    }

    // Bitwise NOT - flip all bits
    int bitwiseNot(int a) {
        return ~a;
    }

    // Left shift - multiply by 2^shift
    int leftShift(int a, int shift) {
        return a << shift;
    }

    // Right shift - divide by 2^shift (for positive numbers)
    int rightShift(int a, int shift) {
        return a >> shift;
    }

    // Check if bit at position i is set (0-indexed from right)
    bool isBitSet(int num, int i) {
        return (num & (1 << i)) != 0;
    }

    // Set bit at position i to 1
    int setBit(int num, int i) {
        return num | (1 << i);
    }

    // Clear bit at position i to 0
    int clearBit(int num, int i) {
        return num & ~(1 << i);
    }

    // Toggle bit at position i
    int toggleBit(int num, int i) {
        return num ^ (1 << i);
    }
};

/*
KEY LEARNINGS:
1. & (AND): 1 only where both bits are 1
2. | (OR): 1 where either bit is 1
3. ^ (XOR): 1 where bits are different
4. ~ (NOT): Flips all bits
5. << (left shift): Multiply by power of 2
6. >> (right shift): Divide by power of 2
7. Use (1 << i) to create bit masks
8. Operations are very fast (O(1))
*/