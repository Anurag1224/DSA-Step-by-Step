# ➗ DAY 5: Math Fundamentals (GCD, LCM, Primes)

**Mathematical Tools That Appear in Every DSA Phase**

---

## 📖 What You'll Learn

Today you master the mathematical foundations that unlock advanced DSA topics:
- **Extended GCD**: Solve equations, find modular inverses, use in cryptography
- **LCM**: Synchronize tasks, work with fractions, find common periods
- **Prime Sieving**: Find all primes efficiently, answer prime queries
- **Prime Factorization**: Decompose numbers, find divisors, solve divisor problems

---

## 🎯 Why This Matters

### Without These Topics:
- ❌ You can't solve "find GCD efficiently"
- ❌ You don't know when to use LCM vs GCD
- ❌ You check if a number is prime slowly (O(√n) each time)
- ❌ You can't solve problems with 10^6 prime queries
- ❌ You don't understand modular arithmetic foundations

### With These Topics:
- ✅ GCD/LCM in O(log n) - instant
- ✅ Answer prime queries in O(1) after O(n log log n) preprocessing
- ✅ Find all divisors efficiently
- ✅ Solve mathematical equations programmatically
- ✅ Foundation for number theory, cryptography, competitive programming

---

## 📝 How to Approach Today

### Phase 1: Understand Concepts (60 minutes)
1. **Read** each code file completely
2. **Dry run** at least 2 examples on paper
3. **Trace** the algorithm step by step
4. Understand the mathematical intuition

### Phase 2: Run & Experiment (45 minutes)
1. Compile and run each `.cpp` file
2. Try different test cases
3. Modify code to test edge cases
4. Observe outputs and verify correctness

### Phase 3: Solve Problems (45 minutes)
1. Design your own test cases
2. Try solving variant problems mentally
3. Implement optimizations discussed
4. Compare different approaches

### Phase 4: Reflect (30 minutes)
1. Which algorithm is fastest for your constraints?
2. What are the gotchas?
3. When would each approach fail?
4. Create a mental model for each concept

---

## 📂 Files Breakdown

### `01_gcd_extended.cpp`
**Concept**: Extended Euclidean Algorithm

**What You'll Learn**:
- How to find coefficients x, y such that `a*x + b*y = gcd(a,b)`
- Recursive vs Iterative implementation
- Solving linear Diophantine equations
- Finding modular multiplicative inverse
- Real-world application: payment distribution

**Key Insight**: 
```
If you can find x,y for the problem,
you can solve many equation-based problems
```

**Time**: O(log(min(a,b))) | **Space**: O(1) iterative

**When to Use**:
- Need to solve `a*x + b*y = c`
- Need modular inverse (finding x where `a*x ≡ 1 (mod m)`)
- Cryptography applications

---

### `02_lcm_basics.cpp`
**Concept**: Least Common Multiple

**What You'll Learn**:
- LCM definition and intuition
- Formula: `LCM(a,b) = (a*b) / GCD(a,b)`
- **CRITICAL**: How to avoid overflow (divide before multiply!)
- LCM of multiple numbers
- Fraction operations with LCM
- Task scheduling applications

**Key Insight**:
```
LCM finds the first number both divide
GCD finds the largest number that divides both
LCM × GCD = a × b (always!)
```

**Time**: O(log(min(a,b))) | **Space**: O(1)

**When to Use**:
- Need common multiple (synchronization)
- Adding fractions with different denominators
- Finding periodic events that coincide
- LCM for multiple numbers

---

### `03_prime_sieve.cpp`
**Concept**: Sieve of Eratosthenes

**What You'll Learn**:
- Efficient prime generation for all numbers ≤ N
- Why Sieve is O(n log log n) instead of O(n√n)
- Optimizations: skip even numbers
- Segmented sieve for large ranges
- Prime gap analysis
- Applications in competitive programming

**Key Insight**:
```
Instead of checking each number individually,
mark off multiples to eliminate composites
```

**Time**: O(n log log n) simple, O(√n) per query | **Space**: O(n)

**When to Use**:
- Multiple prime checks (10+ queries)
- Need ALL primes up to N
- N ≤ 10^7 (memory constraint)
- Range [L, R] where R is huge but R-L is small → segmented sieve

**When NOT to Use**:
- Single prime check (use trial division O(√n))
- N > 10^7 (memory issue, use segmented or other method)

---

### `04_prime_factorization.cpp`
**Concept**: Breaking Numbers Into Primes

**What You'll Learn**:
- Prime factorization algorithm
- Find all divisors (using factorization)
- Count divisors without generating all
- Sum of divisors formula
- Perfect power detection
- GCD/LCM from factorizations

**Key Insight**:
```
Every number uniquely decomposes into primes
From factorization, we can derive ALL properties
```

**Time**: O(√n) factorization, O(d(n)) generate divisors | **Space**: O(log n)

**When to Use**:
- Need all divisors
- Count of divisors
- Sum of divisors
- Check if perfect square/cube
- Solve problems involving divisor properties
- Number theory problems

---

## 🎓 Quick Reference Table

| Problem | Use This | Time | Why |
|---------|----------|------|-----|
| Find GCD | GCD function | O(log n) | Most efficient |
| Find LCM | LCM formula | O(log n) | Derived from GCD |
| Check if prime (1 query) | Trial division | O(√n) | Faster than sieve setup |
| Check if prime (many queries) | Sieve | O(n log log n) | Preprocess once |
| Find all divisors | Factorize | O(√n + d(n)) | Uses factorization |
| Count divisors | Factorize | O(√n) | Formula: ∏(aᵢ+1) |
| Sum of divisors | Factorize | O(√n) | Product formula |
| Solve ax+by=c | Extended GCD | O(log n) | Diophantine solver |
| Find modular inverse | Extended GCD | O(log n) | If gcd(a,m)=1 |

---

## 🧪 Test Strategy

### For Each Algorithm:

```cpp
// 1. Basic Examples (small, easy to verify)
testBasicExamples();      // 12, 18 → GCD=6, LCM=36

// 2. Edge Cases (boundary conditions)
testEdgeCases();          // 0, 1, negatives, large numbers

// 3. Special Cases (unique properties)
testSpecialCases();       // Primes, perfect squares, powers

// 4. Performance Tests (verify time complexity)
testPerformance();        // Measure time for n=10^6
```

---

## 💾 Implementation Patterns

### Pattern 1: GCD & LCM
```cpp
// Always compute GCD first
long long g = gcd(a, b);

// Safe LCM: divide before multiply
long long l = (a / g) * b;  // NOT (a*b) / g
```

### Pattern 2: Prime Checking
```cpp
// Single check
if (isPrime_naive(n)) { ... }  // O(√n)

// Many checks
auto sieve = sieve_Simple(N);
if (sieve[n]) { ... }  // O(1) per check
```

### Pattern 3: Divisor Operations
```cpp
// Need divisors?
auto factors = factorize(n);
auto divisors = generateDivisors(factors);

// Just need count?
long long count = countDivisors(factors);
```

### Pattern 4: Equation Solving
```cpp
// Solve ax + by = c
GCDResult result = extendedGCD(a, b);
if (c % result.gcd != 0) {
    // No solution
} else {
    // Solution exists
    x = result.x * (c / result.gcd);
    y = result.y * (c / result.gcd);
}
```

---

## 🚀 Common Optimizations

### Overflow Prevention
```cpp
// ❌ Wrong
long long result = a * b / gcd(a, b);  // a*b may overflow!

// ✅ Correct
long long result = (a / gcd(a, b)) * b;  // Divide first
```

### Sieve Optimization
```cpp
// Skip even numbers (2x speedup, 50% space)
for (int i = 3; i * i <= n; i += 2) {
    if (is_prime[i]) {
        for (int j = i * i; j <= n; j += 2 * i) {
            is_prime[j] = false;
        }
    }
}
```

### Factorization Optimization
```cpp
// Handle 2 first, then check only odd numbers
while (n % 2 == 0) {
    factors[2]++;
    n /= 2;
}
for (long long i = 3; i * i <= n; i += 2) {
    // ...
}
```

---

## ✅ Before You Submit

- [ ] Tested with at least 5 different test cases
- [ ] Checked edge cases: 0, 1, negatives, large numbers
- [ ] Verified no overflow (used `long long` appropriately)
- [ ] Confirmed time complexity meets constraints
- [ ] Understood the mathematical reasoning
- [ ] Could explain each algorithm to someone else
- [ ] Ready to apply these in real problems

---

## 🎯 Self-Evaluation

After completing Day 5, you should be able to answer:

1. **GCD**: 
   - What is GCD? How to compute it? Time complexity?
   - What is Extended GCD? Why is it useful?
   - How to find modular inverse using Extended GCD?

2. **LCM**:
   - What is LCM? Formula for computing it?
   - Why must we divide before multiplying?
   - When do we need LCM in problems?

3. **Primes**:
   - How does Sieve of Eratosthenes work?
   - Why is it O(n log log n) and not O(n√n)?
   - When to use sieve vs trial division?

4. **Factorization**:
   - How to factorize a number efficiently?
   - How to generate all divisors from factorization?
   - What's the formula for counting divisors?

---

## 🔗 Tomorrow

**Day 6: Bitwise Basics**
- Bit manipulation tricks
- XOR, AND, OR, NOT operations
- Finding single elements, powers of 2
- Building foundation for advanced bit problems

Mathematical mastery opens doors! 🎯
