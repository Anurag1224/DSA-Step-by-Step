# 📝 Day 2 Notes: Modulo, Overflow & Fast Power

**Quick Reference & Interview Tips**

---

## 🔍 Key Concepts Summary

### Integer Overflow
- **What**: Numbers wrap around when exceeding type limits
- **INT_MAX + 1 = INT_MIN** (for 32-bit signed int)
- **Prevention**: Check before operations or use wider types
- **Detection**: `(a > 0 && b > 0 && sum < 0)` for addition overflow

### Modulo Arithmetic
- **Properties**:
  - `(a + b) % MOD = ((a % MOD) + (b % MOD)) % MOD`
  - `(a * b) % MOD = ((a % MOD) * (b % MOD)) % MOD`
  - `(a - b) % MOD = ((a % MOD) - (b % MOD) + MOD) % MOD`
- **Negative numbers**: `(-7) % 3 = 2` in C++ (not -1)
- **Applications**: Cryptography, hashing, cyclic operations

### Fast Exponentiation (Binary Exponentiation)
- **Algorithm**: Square base, halve exponent
- **Time**: O(log exponent) vs O(exponent) for naive
- **Key steps**:
  1. If exponent odd: `result = (result * base) % MOD`
  2. `base = (base * base) % MOD`
  3. `exponent /= 2`

---

## 🧪 Common Test Cases

### Overflow Scenarios
```cpp
// These will overflow silently
int a = INT_MAX;
int b = a + 1;        // Becomes INT_MIN
int c = INT_MIN - 1;  // Becomes INT_MAX
int d = 100000 * 100000;  // Integer overflow
```

### Modulo Edge Cases
```cpp
// Negative modulo
cout << (-7) % 3;     // 2 (not -1)
cout << (-7) % (-3);  // -1 (implementation defined)

// Large numbers
cout << (1000000007LL) % 1000000007;  // 0
cout << (1000000008LL) % 1000000007;  // 1
```

### Fast Power Cases
```cpp
// Basic cases
modPow(2, 10, 1000)   // 1024 % 1000 = 24
modPow(3, 0, MOD)     // 1 (any number^0 = 1)
modPow(0, 5, MOD)     // 0 (0^positive = 0)

// Large exponents
modPow(2, 1000000, MOD)  // Efficient with binary exp
```

---

## 💡 Interview Problem Patterns

### 1. Large Number Computations
**Problem**: Compute `(a^b) % MOD` for large a,b
**Solution**: Binary exponentiation
**Time**: O(log b)

### 2. Factorial with Modulo
**Problem**: Compute `N! % MOD` for N ≤ 10^6
**Solution**: Iterative multiplication with modulo
**Trick**: If MOD ≤ N, result is 0

### 3. Safe Arithmetic
**Problem**: Add/multiply without overflow
**Solution**: Check bounds before operation
**Pattern**: Use `long long` for intermediate results

### 4. Russian Peasant Multiplication
**Problem**: Multiply large numbers efficiently
**Solution**: Double and halve algorithm
**Advantage**: No overflow in intermediate steps

---

## 🚨 Common Mistakes

### 1. Forgetting Overflow Checks
```cpp
// WRONG: Will overflow silently
int sum = 0;
for(int i = 0; i < n; i++) sum += arr[i];

// RIGHT: Check for overflow
long long sum = 0;
for(int i = 0; i < n; i++) {
    if (sum > LLONG_MAX - arr[i]) {
        // Handle overflow
    }
    sum += arr[i];
}
```

### 2. Wrong Modulo with Negatives
```cpp
// WRONG: Assuming (-7) % 3 == -1
int result = (-7) % 3;  // Actually 2 in C++

// RIGHT: Handle negative modulo
int mod(int a, int b) {
    int result = a % b;
    return result < 0 ? result + b : result;
}
```

### 3. Not Using Fast Exponentiation
```cpp
// WRONG: O(exponent) time
long long slowPow(long long base, long long exp, long long mod) {
    long long result = 1;
    for(long long i = 0; i < exp; i++) {
        result = (result * base) % mod;
    }
    return result;
}

// RIGHT: O(log exponent) time
long long fastPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while(exp > 0) {
        if(exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
```

### 4. Integer Division Issues
```cpp
// WRONG: Truncation towards zero
int a = -7, b = 3;
int result = a / b;  // -2 (not -3)

// RIGHT: Be aware of truncation
int quotient = a / b;    // -2
int remainder = a % b;   // -1
// Note: (quotient * b) + remainder = a
```

---

## 🔧 Useful Code Snippets

### Safe Addition
```cpp
bool safeAdd(long long a, long long b, long long& result) {
    if ((b > 0 && a > LLONG_MAX - b) ||
        (b < 0 && a < LLONG_MIN - b)) {
        return false;
    }
    result = a + b;
    return true;
}
```

### Modular Exponentiation
```cpp
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
```

### Russian Peasant Multiplication
```cpp
long long russianMultiply(long long a, long long b) {
    long long result = 0;
    while (b > 0) {
        if (b % 2 == 1) {
            result += a;
        }
        a *= 2;
        b /= 2;
    }
    return result;
}
```

---

## 🎯 Real-World Applications

- **Cryptography**: RSA, Diffie-Hellman, elliptic curves
- **Hash Functions**: MD5, SHA-256 use modulo operations
- **Gaming**: Random number generation, score calculations
- **Financial Systems**: Money calculations requiring precision
- **Scientific Computing**: Large number simulations
- **Competitive Programming**: Almost every problem with constraints > 10^9

---

## 📚 Quick Reference

```
| Operation      | Time Complexity | Safe Range (64-bit)           |
|----------------|-----------------|-------------------------------|
| Addition       | O(1)            | -9.2e18 to 9.2e18             |
| Multiplication | O(1)            | -3e9 to 3e9 (for no overflow) |
| Fast Power     | O(log exp)      | Exponents up to 10^18         |
| Factorial      | O(N)            | N up to 20 (without modulo)   |
```
**Remember**: When in doubt, use `long long` and check for overflow!