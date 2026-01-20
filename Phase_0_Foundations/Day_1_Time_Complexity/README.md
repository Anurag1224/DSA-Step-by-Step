# ⏱️ DAY 1: Time & Space Complexity

**Learn to measure algorithm efficiency without running it.**

---

## 🎯 Goal of Day 1

By the end of today, you will:

✅ Understand what time complexity actually means  
✅ Stop fearing brute force  
✅ Learn how optimization is discovered  
✅ Recognize O(n), O(n²), O(log n) patterns instantly  
✅ Think about complexity before coding  

---

## 1️⃣ What is Time Complexity?

**Simple Definition:**
How does execution time grow as input grows?

We don't measure seconds. We measure **growth trend**.

### Analogy
If:
- 10 items take 1 second
- 100 items take 10 seconds
- 1000 items take 100 seconds

Growth is **proportional to input** → **O(n)**

### Real Example
```
Input Size    Time (approx)    Pattern
10            1 ms             
100           10 ms            
1000          100 ms           (grows 10x per 10x input)
10000         1000 ms          
```

This is **linear growth** → **O(n)**

---

## 2️⃣ Why Complexity Matters (Real-World)

### Scenario: Processing 1 Million Users

Algorithm	Time for 1M users	Practical?
O(n)	1 second	✅ Yes
O(n²)	1 million seconds (11 days)	❌ No

Your O(n²) algorithm that worked fine with 1000 users **completely breaks** with 1 million.

This is how **production systems fail**.

---

## 3️⃣ Common Time Complexities (You Must Know These)

```
Complexity    Pattern              When?
O(1)          Constant             Direct access
O(log n)      Divide by 2          Binary search
O(n)          Single loop          Traversal
O(n log n)    Loop + divide        Merge sort
O(n²)         Nested loop          Nested iterations
O(n³)         Triple nested        3D problems
O(2ⁿ)         Exponential          Subsets, permutations
O(n!)         Factorial            All arrangements
```

### Visual Comparison

```
Complexity    10 items    100 items    1000 items
O(1)          1           1            1
O(log n)      3           7            10
O(n)          10          100          1000
O(n²)         100         10,000       1,000,000
O(2ⁿ)         1024        Too Large    Impossible
```

Notice: O(n²) becomes impractical very quickly.

---

## 4️⃣ Time Complexity Analysis (Step by Step)

### Example 1: Single Loop (O(n))

```cpp
for (int i = 0; i < n; i++) {
    cout << i;  // constant work
}
```

**Analysis:**
- Loop runs `n` times
- Inside: constant work (printing is O(1))
- Total: `n * 1 = n` operations
- **Complexity: O(n)**

### Example 2: Nested Loops (O(n²))

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        cout << "*";  // constant work
    }
}
```

**Analysis:**
- Outer loop: n times
- Inner loop: n times (for each outer iteration)
- Total: `n * n = n²` operations
- **Complexity: O(n²)**

### Example 3: Loop that Halves (O(log n))

```cpp
int count = 0;
while (n > 0) {
    n = n / 2;
    count++;
}
```

**Analysis:**
- Each step divides by 2
- n → n/2 → n/4 → n/8 → 1
- Takes `log₂(n)` steps
- **Complexity: O(log n)**

Example: n = 1000 → takes ~10 steps (since 2¹⁰ = 1024)

### Example 4: Single Loop + Single Loop (O(n))

```cpp
for (int i = 0; i < n; i++) {
    cout << i;
}

for (int j = 0; j < n; j++) {
    cout << j;
}
```

**Analysis:**
- First loop: n times
- Second loop: n times
- Total: `n + n = 2n`
- Drop constant: **O(n)**

Rule: **Drop constants, keep dominant term**

---

## 5️⃣ Space Complexity (Often Ignored)

**Definition:** Extra memory used (excluding input).

### Example 1: No Extra Space (O(1))

```cpp
int countDigits(int n) {
    int count = 0;      // one variable
    while (n > 0) {
        n /= 10;
        count++;
    }
    return count;
}
```

Uses: Only one variable `count`, doesn't grow with input.
**Space: O(1)**

### Example 2: Array Space (O(n))

```cpp
vector<int> arr(n);     // array of size n
for (int i = 0; i < n; i++) {
    arr[i] = i;
}
```

Uses: Array of size `n`.
**Space: O(n)**

### Example 3: Recursive Stack Space (O(n))

```cpp
void printNumbers(int n) {
    if (n == 0) return;
    cout << n;
    printNumbers(n - 1);    // recursive call
}
```

Uses: Call stack depth = n
**Space: O(n)**

---

## 6️⃣ Brute Force is OK (Key Insight!)

### Why Brute Force First?

Interviewers expect:

1. **Correct solution** (even if slow)
2. **Then optimize** (if needed)

They test:
- Can you think logically?
- Can you code correctly?
- Can you identify optimization?

They DON'T expect instant perfection.

### Example: Sum from 1 to N

**Brute Force (O(n))**
```cpp
int sum = 0;
for (int i = 1; i <= n; i++) {
    sum += i;
}
```
✅ Correct
❌ Slow for large n

**Optimized (O(1))**
```cpp
int sum = n * (n + 1) / 2;
```
✅ Correct
✅ Fast

**Interview Talk:**
> "I'll first solve it with a loop to ensure correctness, then optimize using the mathematical formula."

That's exactly what interviewers want to hear.

---

## 7️⃣ Big-O Rules (Important!)

### Rule 1: Drop Constants

```
O(2n) → O(n)
O(5n²) → O(n²)
O(3n + 2) → O(n)
```

Why? For large n, constants don't matter.

### Rule 2: Drop Non-Dominant Terms

```
O(n² + n) → O(n²)        (n² dominates)
O(n + log n) → O(n)      (n dominates)
O(2ⁿ + n²) → O(2ⁿ)       (2ⁿ dominates)
```

### Rule 3: Multiplicative Complexity

```
Nested loops multiply:
for i:       n times
  for j:     n times
  Total:     n * n = n²

Loop + half:
for i:       n times
  while:     log n halving
  Total:     n * log n = O(n log n)
```

---

## 8️⃣ Space Complexity in Recursion

### Depth = Stack Space

```cpp
void countdown(int n) {
    if (n == 0) return;
    cout << n;
    countdown(n - 1);    // adds to call stack
}
```

**Stack Trace:**
```
countdown(5)
  countdown(4)
    countdown(3)
      countdown(2)
        countdown(1)
          countdown(0) → return
```

Depth = 5 → **Space = O(5) = O(n)**

---

## 9️⃣ Edge Case Thinking for Complexity

### Consider Constraints

```cpp
// If n ≤ 1000: even O(n²) is fine
if (n ≤ 1000) {
    // O(n²) ~ 1,000,000 operations ✅
}

// If n ≤ 10⁶: need O(n) or O(n log n)
if (n ≤ 1000000) {
    // O(n²) ~ 10¹² operations ❌ Too slow
}

// If n ≤ 20: even O(2ⁿ) might work
if (n ≤ 20) {
    // O(2ⁿ) ~ 1,000,000 operations ✅
}
```

**Rule of Thumb:**
- O(n) → 10⁸ operations ✅
- O(n²) → 10⁴ operations ✅
- O(n³) → 500 operations ✅

---

## 🔟 How Systems Break When Complexity is Ignored

### Scenario 1: E-Commerce Login

**System:** Process 10 million logins per day

Algorithm A: O(n²) lookup
```
10 million² = 10¹⁴ operations
Time: ~10⁶ seconds = weeks ❌
```

Algorithm B: O(n) with hashing
```
10 million = 10⁷ operations
Time: ~0.01 seconds ✅
```

**Impact:** Wrong algorithm → system completely unusable.

### Scenario 2: Deep Recursion

```cpp
void dfs(int n) {  // depth = n
    dfs(n - 1);
}
dfs(10000);  // crashes
```

**Result:** Stack overflow → app crash → users lose trust.

### Scenario 3: Large Data Overnight

- System works fine with 1000 users
- Startup grows to 1 million users
- O(n²) algorithm now takes minutes per operation
- **"System used to be fast, what happened?"**

Answer: Didn't think about complexity.

---

## 📋 PRACTICE PROBLEMS (DAY 1)

We'll work through 4 problems step by step:

### Problem 1: Count Digits
Given a number, count its digits.

- Input: 12345 → Output: 5
- Input: 0 → Output: 1
- Input: -123 → Output: 3

### Problem 2: Reverse a Number
Reverse the digits of a number.

- Input: 1234 → Output: 4321
- Input: 1200 → Output: 21 (leading zeros removed)
- Input: 0 → Output: 0

### Problem 3: Palindrome Number
Check if a number is a palindrome.

- Input: 121 → Output: true
- Input: -121 → Output: false
- Input: 0 → Output: true

### Problem 4: GCD (Greatest Common Divisor)
Find the largest number dividing both.

- Input: 24, 36 → Output: 12
- Input: 5, 10 → Output: 5
- Input: 7, 13 → Output: 1

---

## 🧠 How to Approach These Problems

For each problem:

1. **Understand** — What does it ask?
2. **Dry run** — Trace on examples manually
3. **Think brute force** — Simplest correct solution
4. **Analyze complexity** — Why is it slow/fast?
5. **Identify optimization** — What's repeated?
6. **Code it** — Write the solution
7. **Test edge cases** — Zero, negative, large
8. **Compare & learn** — Review the solution

---

## 🧼 Best Practices for Today

✔️ Use meaningful variable names (`digitCount`, not `c`)  
✔️ Handle zero explicitly  
✔️ Handle negatives explicitly  
✔️ Comment why, not what  
✔️ Test before submitting  
✔️ Dry run your code manually first  

---

## 💥 Real-World Impact

These 4 problems teach:

- **Number systems** — how integers work
- **Edge cases** — why they matter
- **Complexity** — why efficiency matters
- **Clean code** — how professionals code
- **System thinking** — how this appears in production

Not just "DSA practice problems."

Real engineering thinking.

---

## 📚 Resources

- [Big-O Visualization](https://www.bigocheatsheet.com/)
- [Recursion Stack Visualization](https://pythontutor.com/cpp.html)
- [Algorithm Complexity Calculator](https://runtimecomplexity.org/)

---

## Next Step

When you're ready, solve the 4 problems:

1. **Count Digits** — [Solution](01_count_digits.cpp)
2. **Reverse Number** — [Solution](02_reverse_number.cpp)
3. **Palindrome Number** — [Solution](03_palindrome_number.cpp)
4. **GCD Euclidean** — [Solution](04_gcd_euclidean.cpp)

For each problem:
- Write thinking in your own words
- Code your solution
- List edge cases you handled
- Measure time & space complexity
- Compare with provided solution

---

**You're starting the right way. Let's go! 💪**
