# 📐 DAY 5: MATH FUNDAMENTALS - QUICK REFERENCE

**Mathematical Tools That Unlock DSA**

---

## 📚 CORE CONCEPTS

### 1. Extended GCD (Euclidean Algorithm)
**What**: Find `x, y` such that `a*x + b*y = gcd(a,b)`

**Formula**: 
```
if b == 0: return (a, 1, 0)
else: solve for (b, a%b), then backtrack
```

**Time**: `O(log(min(a,b)))`

**Uses**:
- Solve linear Diophantine equations
- Find modular multiplicative inverse
- Cryptography (RSA)

**Key Point**: Use iterative version to avoid stack overflow

---

### 2. LCM (Least Common Multiple)
**What**: Smallest positive integer divisible by both `a` and `b`

**Formula**: 
```
LCM(a,b) = (a * b) / GCD(a,b)
```

**Critical**: Divide FIRST to avoid overflow!
```cpp
long long result = (a / gcd(a,b)) * b;  // ✓ Correct
long long result = (a * b) / gcd(a,b);  // ✗ Can overflow
```

**Time**: `O(log(min(a,b)))`

**Uses**:
- Task synchronization/scheduling
- Fraction operations
- Finding common periods
- LCM of multiple numbers

**Key Point**: LCM × GCD = a × b (always!)

---

### 3. Sieve of Eratosthenes
**What**: Find all primes up to N efficiently

**Algorithm**:
```
mark all as prime
for i from 2 to √n:
    if i is prime:
        mark all multiples of i as non-prime
```

**Time**: `O(n log log n)` - Very fast!

**Space**: `O(n)`

**Variants**:
- **Simple**: Easy to understand, standard
- **Optimized**: Only track odd numbers (2x speedup, 50% space)
- **Segmented**: For large ranges [L, R], use primes up to √R

**Key Point**: Start marking from `i²`, not `i`

**Uses**:
- Count primes up to N
- Check primality for multiple values
- Prime gap analysis
- Number theory problems

---

### 4. Prime Factorization
**What**: Express number as product of primes

**Formula**: 
```
Every integer > 1 = p₁^a₁ × p₂^a₂ × ... × pₖ^aₖ
```

**Algorithm**:
```cpp
for i = 2 to √n:
    while n % i == 0:
        factors[i]++
        n /= i
if n > 1: factors[n]++
```

**Time**: `O(√n)`

**Space**: `O(log n)` for storing factors

**Key Formulas**:
- **Number of divisors**: `(a₁+1)(a₂+1)...(aₖ+1)`
- **Sum of divisors**: `∏(1 + p + p² + ... + p^a) / (p-1)`
- **Is perfect square**: All exponents divisible by 2
- **Is perfect power k**: All exponents divisible by k

**Uses**:
- Finding all divisors
- GCD/LCM calculations
- Perfect power detection
- Divisor sum problems
- Prime factorization-based optimizations

---

## ⚡ TIME COMPLEXITIES CHEAT SHEET

| Operation | Time | When to Use |
|-----------|------|------------|
| GCD | `O(log(min(a,b)))` | Any GCD query |
| LCM | `O(log(min(a,b)))` | Multiple queries on same pair |
| Prime Check (single) | `O(√n)` | Single check |
| Prime Check (multiple) | Sieve: `O(n log log n)` | Many checks up to N |
| Factorize | `O(√n)` | Single factorization |
| Sieve | `O(n log log n)` | Find all primes ≤ N |
| Get divisors | `O(d(n))` | When d(n) is small |
| Sum of divisors | `O(√n)` | Using factorization |

---

## 🚨 COMMON MISTAKES & SOLUTIONS

### Mistake 1: Overflow in GCD calculations
```cpp
❌ long long result = a * b / gcd(a, b);  // a*b can overflow!
✅ long long result = (a / gcd(a, b)) * b;  // Divide first
```

### Mistake 2: Not marking 0,1 in sieve
```cpp
❌ for (int i = 2; i <= n; i++)  // Forgets to mark 0, 1
✅ is_prime[0] = is_prime[1] = false;
```

### Mistake 3: Wrong loop bound in factorization
```cpp
❌ for (long long i = 2; i <= n; i++)  // Too slow!
✅ for (long long i = 2; i * i <= n; i++)  // Correct
```

### Mistake 4: Not handling i*i overflow
```cpp
❌ for (long long i = 2; i * i <= n; i++)  // Overflow for large i!
✅ for (long long i = 2; i <= sqrt(n); i++)  // Or check differently
```

### Mistake 5: Sieve starting from wrong index
```cpp
❌ for (int j = i; j <= n; j += i)  // Marks i itself!
✅ for (int j = i * i; j <= n; j += i)  // Correct
```

### Mistake 6: Modular inverse without checking GCD
```cpp
❌ long long inv = modularInverse(a, m);  // May not exist!
✅ if (gcd(a, m) == 1) inv = modularInverse(a, m);
```

---

## 💡 INTUITION & VISUALIZATION

### GCD as Largest Rectangle
```
Find largest square that fits in 12×18 rectangle exactly
Answer: 6×6 (can fit 2×3 = 6 squares)
GCD(12,18) = 6
```

### LCM as Synchronization
```
Train A every 12 min, Train B every 18 min
When both depart together?
After LCM(12,18) = 36 minutes
```

### Sieve as Elimination
```
Cross out multiples of 2: ~~4~~, ~~6~~, ~~8~~, ...
Cross out multiples of 3: ~~9~~, ~~15~~, ...
Remaining: 2, 3, 5, 7, 11, 13, ... (all primes!)
```

### Prime Factorization as Decomposition
```
30 = 2 × 15
   = 2 × 3 × 5 (can't decompose further)

Understanding: 30 "breaks down" into three prime pieces
```

---

## 🎯 PROBLEM PATTERNS

### Pattern 1: "Find GCD/LCM"
- Use formulas: `gcd(a,b)` or `lcm(a,b) = a*b/gcd(a,b)`

### Pattern 2: "How many divisors?"
- Factorize, use formula: `∏(aᵢ+1)`

### Pattern 3: "Find all divisors"
- Factorize, generate all combinations of prime powers

### Pattern 4: "Check if N is a perfect square/cube"
- Factorize, check if all exponents divisible by 2 (for square) or 3 (for cube)

### Pattern 5: "Count primes up to N"
- Use Sieve of Eratosthenes

### Pattern 6: "Prime check for many numbers"
- Use Sieve if checking all up to N
- Use trial division if only checking specific numbers

### Pattern 7: "Solve ax + by = c"
- Use Extended GCD to check if solution exists
- If gcd(a,b) divides c, find solution via Extended GCD

---

## 🔗 RELATIONSHIP CHAINS

```
Extended GCD
    ↓
Modular Inverse (a⁻¹ mod m)
    ↓
Diophantine Equations
    ↓
Cryptography (RSA)

↓

Prime Factorization
    ↓
All Divisors / Divisor Count / Sum of Divisors
    ↓
Number Theory Problems

↓

Sieve of Eratosthenes
    ↓
Prime Queries / Prime Gaps / Prime Counting
    ↓
Advanced Problems
```

---

## ✅ CHECKLIST BEFORE SUBMISSION

- [ ] Checked for overflow in ALL multiplications
- [ ] Used `long long` where needed (not `int`)
- [ ] Handle edge cases: 0, 1, negative numbers
- [ ] Used `abs()` where appropriate
- [ ] For sieve: marked 0, 1 as non-prime
- [ ] For large numbers: used appropriate algorithm (segmented sieve, Pollard's rho)
- [ ] Verified with small test cases first
- [ ] Checked time limit (sieve OK for n ≤ 10^7, factorize OK for n ≤ 10^9)

---

## 🎓 WHEN TO USE EACH TOPIC IN INTERVIEWS

| Topic | Interview Frequency | Difficulty |
|-------|-------------------|-----------|
| GCD/LCM | High | Easy |
| Extended GCD | Medium | Medium |
| Prime Checking | High | Easy |
| Sieve | Medium | Easy |
| Factorization | Medium | Easy |
| Modular Inverse | Low | Medium |

---

## 📖 PROBLEM SOLVING FLOW

```
Given a problem involving primes/divisors:

1. Do I need ALL primes ≤ N?
   → Sieve
   
2. Do I need GCD or LCM?
   → Use formulas directly
   
3. Do I need divisors?
   → Factorize, then generate
   
4. Do I need solve ax + by = c?
   → Extended GCD
   
5. Do I need modular inverse?
   → Extended GCD (verify gcd = 1)
   
6. Performance critical?
   → Check constraints
   → Use optimized variant if needed
```

---
