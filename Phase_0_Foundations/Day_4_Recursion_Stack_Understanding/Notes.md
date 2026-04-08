# 📝 Day 4 Notes: Recursion Stack Understanding

## Quick Summary

Today you learned:
- ✅ How recursion consumes stack memory
- ✅ Why deep recursion causes stack overflow crashes
- ✅ How to calculate safe recursion depth limits
- ✅ When to use iteration instead of recursion

---

## How Recursion Works in Memory

### Stack Frames
Each recursive call creates a **stack frame** containing:
- Local variables
- Function parameters
- Return address
- Previous frame pointer

### Stack Overflow
- Default stack size: ~1MB (varies by system)
- Each frame: ~100-200 bytes
- Max safe depth: ~5,000-10,000 calls (depends on function)

### Example: Factorial Recursion
```cpp
long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);  // Each call waits for next
}
```

**Stack for factorial(5):**
```
factorial(5) → factorial(4) → factorial(3) → factorial(2) → factorial(1)
     ↑             ↑             ↑             ↑             ↑
   5 * result   4 * result   3 * result   2 * result       1
```

---

## Problem 1: Factorial with Recursion

### Key Points
- **Algorithm:** Base case + recursive case
- **Stack Depth:** O(n) frames for input n
- **Time:** O(n) operations
- **Space:** O(n) stack space

### Common Mistakes
```cpp
// ❌ WRONG: No base case handling
long long factorial(int n) {
    return n * factorial(n - 1);  // Stack overflow for n=0
}

// ✓ CORRECT: Handle base case
long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
```

### Interview Tip
Say: "Factorial recursion uses O(n) stack space because each call waits for the result of the next call."

---

## Problem 2: Fibonacci with Recursion

### Key Points
- **Algorithm:** Sum of two previous numbers
- **Time:** O(2^n) - exponential explosion
- **Space:** O(n) stack depth
- **Problem:** Same subproblems solved multiple times

### Stack Analysis
```
fib(5) calls fib(4) and fib(3)
fib(4) calls fib(3) and fib(2)
fib(3) calls fib(2) and fib(1)
...and so on
```

### Why It Crashes
- For n=50: ~2^50 operations (quadrillions)
- Stack depth 50 is fine, but time is infinite

### Interview Tip
Say: "Naive Fibonacci recursion is O(2^n) time because it recalculates the same values exponentially many times."

---

## Problem 3: Tower of Hanoi

### Key Points
- **Algorithm:** Move n-1 disks first, then nth, then n-1 again
- **Time:** O(2^n) moves
- **Stack Depth:** O(n) maximum depth
- **Insight:** Recursion depth equals number of disks

### Recursion Tree
```
hanoi(3, A, B, C):
  hanoi(2, A, C, B)  // Move 2 disks out of way
    hanoi(1, A, B, C)
      move A→C
    move A→B
    hanoi(1, C, A, B)
      move C→B
  move A→C          // Move largest disk
  hanoi(2, B, A, C)  // Move 2 disks on top
    ...and so on
```

### Interview Tip
Say: "Tower of Hanoi demonstrates that some problems have exponential time complexity even with optimal algorithms."

---

## Problem 4: Safe Recursion Depth

### Key Points
- **Algorithm:** Add depth counter to prevent overflow
- **Stack Limit:** Check before recursing
- **Alternative:** Use iteration or increase stack size

### Implementation
```cpp
const int MAX_DEPTH = 1000;

long long safe_factorial(int n, int depth = 0) {
    if (depth > MAX_DEPTH) {
        throw std::runtime_error("Recursion depth exceeded");
    }
    if (n <= 1) return 1;
    return n * safe_factorial(n - 1, depth + 1);
}
```

### Interview Tip
Say: "I add a depth counter to prevent stack overflow in production code, or use iterative solutions for deep recursion."

---

## When to Use Recursion vs Iteration

### Use Recursion When:
- Problem has natural recursive structure (trees, graphs)
- Depth is small and bounded
- Code clarity is more important than efficiency
- Language supports tail call optimization

### Use Iteration When:
- Depth could be large (>1000)
- Performance is critical
- You need to manage memory explicitly
- Converting to iteration is straightforward

### Converting Recursion to Iteration
```cpp
// Recursive factorial
long long factorial_rec(int n) {
    if (n <= 1) return 1;
    return n * factorial_rec(n - 1);
}

// Iterative factorial
long long factorial_iter(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}
```

---

## System Stack Limits

### Typical Limits:
- **Windows:** 1MB default stack
- **Linux:** 8MB default stack
- **macOS:** 8MB default stack

### Increasing Stack Size:
```bash
# Linux/Mac
ulimit -s 65536  # 64MB stack

# Or in code (not recommended for production)
#pragma comment(linker, "/STACK:20000000")  // Windows
```

### Interview Tip
Say: "Stack size limits vary by OS, so I design algorithms to use O(log n) stack space when possible."

---

## Common Interview Questions

1. **Why does recursion cause stack overflow?**
   - Each call creates a stack frame; too many frames exceed memory limit

2. **What's the maximum recursion depth in C++?**
   - ~10,000-50,000 depending on function and system

3. **When should you avoid recursion?**
   - When depth could exceed 1000, or when iteration is simpler

4. **What's tail recursion?**
   - When recursive call is the last operation; can be optimized to iteration

---

## Key Takeaways

- Recursion is powerful but stack-intensive
- Always consider depth limits in recursive functions
- Use iteration for deep or performance-critical code
- Understand your system's stack constraints
- Profile recursion depth in testing