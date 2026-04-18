# 🔢 DAY 6: Bitwise Basics

**Efficient manipulation at the bit level. Pattern recognition that saves time.**

---

## 🎯 Goal of Day 6

By the end of today, you will:

✅ Understand binary representation intuitively  
✅ Master bitwise operations (AND, OR, XOR, shifts)  
✅ Check if number is power of 2 in O(1) time  
✅ Count set bits efficiently  
✅ Use XOR for finding unique elements  
✅ Think in binary for optimization opportunities  

---

## 1️⃣ Why Bitwise Operations Matter

**Simple Definition:**
Direct manipulation of individual bits for efficiency and clever solutions.

### Real-World Impact
- **Memory efficiency:** Store multiple flags in one integer
- **Performance:** Bit operations are faster than arithmetic
- **Problem solving:** XOR tricks, bit masks, state compression
- **System programming:** Hardware control, permissions, networking

### Analogy
If variables are like drawers, bits are like individual switches inside each drawer.

---

## 2️⃣ Binary Representation (Foundation)

Every integer is stored as 32 or 64 bits of 0s and 1s.

### Example: 13 in Binary
```
Decimal: 13
Binary:  0000 0000 0000 0000 0000 0000 0000 1101
         └─────────────── 32 bits ──────────────┘

Bit positions:  31  30  ...  3   2   1   0
Values:         2³¹     ... 8   4   2   1
```

**Key Insight:** Each bit represents a power of 2.

---

## 3️⃣ Core Bitwise Operations

### AND (&) - Bitwise Intersection
```
A:  0000 1101 (13)
B:  0000 1011 (11)
A&B: 0000 1001 (9)

Use: Check if specific bits are set
```

### OR (|) - Bitwise Union
```
A:  0000 1101 (13)
B:  0000 1011 (11)
A|B: 0000 1111 (15)

Use: Set specific bits to 1
```

### XOR (^) - Bitwise Exclusive OR
```
A:  0000 1101 (13)
B:  0000 1011 (11)
A^B: 0000 0110 (6)

Use: Toggle bits, find unique elements
```

### NOT (~) - Bitwise Complement
```
A:  0000 1101 (13)
~A: 1111 0010 (-14 in two's complement)

Use: Flip all bits
```

### Left Shift (<<) - Multiply by 2
```
13 << 1 = 26  (13 * 2¹)
13 << 2 = 52  (13 * 2²)
13 << 3 = 104 (13 * 2³)
```

### Right Shift (>>) - Divide by 2
```
13 >> 1 = 6   (13 / 2¹)
26 >> 2 = 6   (26 / 2²)
```

---

## 4️⃣ Common Bitwise Patterns

### Check if Power of 2
```cpp
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}
```
**Why it works:** Powers of 2 have exactly one bit set.

### Count Set Bits (Hamming Weight)
```cpp
int countBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
```

### Find Single Number (XOR Trick)
```cpp
int findUnique(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;  // XOR cancels duplicates
    }
    return result;
}
```

---

## 5️⃣ Bitwise Applications

### Bit Masks for Permissions
```cpp
const int READ = 1;    // 0001
const int WRITE = 2;   // 0010
const int EXECUTE = 4; // 0100

int permissions = READ | WRITE;  // 0011
bool canRead = permissions & READ;
```

### State Compression
Store multiple boolean flags in one integer:
```cpp
int state = 0;
state |= (1 << 0);  // Set flag 0
state |= (1 << 5);  // Set flag 5
bool flag0 = state & (1 << 0);
```

---

## 📝 Practice Problems

1. **Bitwise AND/OR/XOR Operations**
2. **Power of 2 Check**
3. **Count Set Bits**
4. **Single Number in Array**
5. **Bit Manipulation for Efficiency**

---

## 🎯 Key Takeaways

- **Binary thinking** unlocks optimization opportunities
- **Bit operations are O(1)** and very fast
- **XOR is magical** for finding duplicates/uniques
- **Bit masks** enable efficient state management
- **Shifts** replace multiplication/division by powers of 2

---

## 🔗 Next Steps

Tomorrow: **Dry Run & Problem-Solving Mindset**

> "Bits are the atoms of computing. Master them."