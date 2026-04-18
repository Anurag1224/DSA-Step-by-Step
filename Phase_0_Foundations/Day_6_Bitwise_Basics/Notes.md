# 📝 Day 6 Notes: Key Learnings & Gotchas

## Quick Summary

Today you learned:
- ✅ Binary representation and bit manipulation
- ✅ Core bitwise operations (AND, OR, XOR, shifts)
- ✅ Power of 2 detection with bit tricks
- ✅ Counting set bits efficiently
- ✅ XOR for finding unique elements
- ✅ Bit masks and state compression

---

## Binary Representation

### Key Points
- **Every integer** is stored as 32/64 bits of 0s and 1s
- **Each bit** represents a power of 2
- **Position 0** (rightmost) = 2⁰ = 1
- **Position 1** = 2¹ = 2
- **Position 31** = 2³¹ = 2,147,483,648

### Common Mistakes
```cpp
// ❌ WRONG: Thinking decimal and binary are the same
int x = 10;  // Decimal 10 = Binary 1010

// ✓ CORRECT: Use binary literals when helpful
int mask = 0b1010;  // Binary 1010 = Decimal 10
```

---

## Bitwise Operations

### AND (&) - Check/Mask Bits
```cpp
// Check if bit 2 is set (0-indexed from right)
bool bit2Set = (num & (1 << 2)) != 0;

// Clear all bits except last 4
int last4Bits = num & 0b1111;
```

### OR (|) - Set Bits
```cpp
// Set bit 3 to 1
num |= (1 << 3);

// Set multiple bits
num |= (1 << 0) | (1 << 5);  // Set bits 0 and 5
```

### XOR (^) - Toggle/Find Unique
```cpp
// Toggle bit 1
num ^= (1 << 1);

// Find single number (appears once)
int single = 0;
for(int x : nums) single ^= x;  // XOR cancels pairs
```

### Shifts (<<, >>)
```cpp
// Multiply by 8 (faster than num * 8)
int result = num << 3;

// Divide by 4 (for positive numbers)
int result = num >> 2;

// Extract bits 4-7
int bits47 = (num >> 4) & 0b1111;
```

---

## Power of 2 Check

### Key Points
- **Powers of 2** have exactly one bit set in binary
- **n & (n-1)** clears the lowest set bit
- **For powers of 2:** n & (n-1) == 0

### Examples
```
8:  1000  & 0111 = 0000  ✓ Power of 2
10: 1010  & 1001 = 1000  ❌ Not power of 2
```

### Edge Cases
```cpp
// Handle zero and negatives
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}
```

---

## Count Set Bits

### Method 1: Loop (Simple)
```cpp
int countBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;  // Check LSB
        n >>= 1;         // Shift right
    }
    return count;
}
```

### Method 2: Brian Kernighan (Efficient)
```cpp
int countBits(int n) {
    int count = 0;
    while (n) {
        n &= n - 1;  // Clear lowest set bit
        count++;
    }
    return count;
}
```

---

## XOR Tricks

### Find Single Number
```cpp
// Array where all elements appear twice except one
int findSingle(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;  // XOR cancels duplicates
    }
    return result;
}
```

### Swap Without Temp Variable
```cpp
// Swap a and b
a ^= b;
b ^= a;
a ^= b;
```

### Find Two Unique Numbers
```cpp
// Array where all appear twice except two numbers
pair<int, int> findTwoUnique(vector<int>& nums) {
    int xor_all = 0;
    for (int num : nums) xor_all ^= num;

    // Find rightmost set bit
    int rightmost = xor_all & -xor_all;

    int num1 = 0, num2 = 0;
    for (int num : nums) {
        if (num & rightmost) num1 ^= num;
        else num2 ^= num;
    }

    return {num1, num2};
}
```

---

## Bit Masks & Flags

### Permission System
```cpp
const int READ = 1 << 0;    // 0001
const int WRITE = 1 << 1;   // 0010
const int EXECUTE = 1 << 2; // 0100

int userPerms = READ | WRITE;  // 0011

// Check permissions
bool canRead = userPerms & READ;
bool canWrite = userPerms & WRITE;

// Add permission
userPerms |= EXECUTE;

// Remove permission
userPerms &= ~WRITE;
```

---

## Common Interview Questions

### Q: Check if ith bit is set
```cpp
bool isSet(int num, int i) {
    return (num & (1 << i)) != 0;
}
```

### Q: Set ith bit
```cpp
int setBit(int num, int i) {
    return num | (1 << i);
}
```

### Q: Clear ith bit
```cpp
int clearBit(int num, int i) {
    return num & ~(1 << i);
}
```

### Q: Toggle ith bit
```cpp
int toggleBit(int num, int i) {
    return num ^ (1 << i);
}
```

---

## Performance Benefits

### Why Use Bitwise?
- **Faster than arithmetic:** Bit operations are CPU-native
- **Memory efficient:** Pack multiple flags into one int
- **Cleaner code:** Express intent clearly
- **Interview favorite:** Shows deep understanding

### Real-World Examples
- **Game development:** Entity state flags
- **Operating systems:** File permissions
- **Networking:** Protocol flags
- **Compression:** Bit-level data packing

---

## Gotchas & Edge Cases

### Negative Numbers
```cpp
// Right shift on negative numbers (implementation defined)
int x = -8;
int y = x >> 1;  // May or may not sign-extend

// Use unsigned for predictable behavior
unsigned int z = static_cast<unsigned int>(x) >> 1;
```

### Integer Overflow
```cpp
// Left shift can overflow
int x = 1 << 31;  // Undefined behavior (UB)

// Safe version
if (i < 32) x = 1 << i;
```

### Two's Complement
```cpp
// NOT operation on signed int gives negative
int x = 5;   //  0000...0101
int y = ~x;  //  1111...1010 = -6 in two's complement
```

---

## Practice Tips

1. **Convert manually:** Practice decimal ↔ binary conversion
2. **Visualize bits:** Draw 32-bit representations
3. **Use bit tricks:** Replace arithmetic where possible
4. **Think flags:** Use bit masks instead of bool arrays
5. **XOR practice:** Master the "cancel pairs" pattern

---

## Next Steps

Tomorrow: **Dry Run & Problem-Solving Mindset**

> "Bits are the building blocks. Master them, and algorithms become poetry."