# 📝 DAY 19 Notes: Problem-Solving Patterns

## Key Concepts

### Patterns with Mathematical Intent

Move beyond pure visual patterns to **problems with meaning**:
- Floyd's Triangle (famous interview pattern)
- Pascal's Triangle (combinatorics)
- Prime numbers in patterns
- Fibonacci sequence
- Spiral grids

---

## Famous Patterns

### Floyd's Triangle (MUST KNOW!)

```
1
2 3
4 5 6
7 8 9 10
```

**Logic:**
- Row i has i elements
- Use global counter incrementing continuously
- Popular in interviews!

```cpp
int num = 1;
for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) {
        cout << num++ << " ";
    }
    cout << "\n";
}
```

### Pascal's Triangle (Combinatorics)

```
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
```

**Logic:**
- Entry at (i,j) = C(i,j) = i!/(j!(i-j)!)
- Each entry = sum of two above
- Uses mathematical combination formula

```cpp
int val = 1;
for (int j = 0; j <= i; j++) {
    cout << val << " ";
    val = val * (i - j) / (j + 1);
}
```

### Prime Number Pattern

```
2 3
5 7 11
13 17 19 23
```

**Logic:**
- Row i contains i prime numbers
- Need prime-checking function
- Test each candidate

```cpp
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int num = 2;
for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
        while (!isPrime(num)) num++;
        cout << num++ << " ";
    }
    cout << "\n";
}
```

### Fibonacci Pattern

```
1
1 1
2 3 5
8 13 21 34
```

**Logic:**
- Generate Fibonacci sequence first
- Use sequence in triangle pattern

```cpp
vector<long long> fib;
fib.push_back(1);
fib.push_back(1);

while (fib.size() < n * (n + 1) / 2) {
    fib.push_back(fib[fib.size()-1] + fib[fib.size()-2]);
}

int idx = 0;
for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
        cout << fib[idx++] << " ";
    }
    cout << "\n";
}
```

### Spiral Pattern (2D Array)

```
1 2 3
8 9 4
7 6 5
```

**Logic:**
- Fill matrix in spiral order
- Four directions: right, down, left, up
- Track boundaries shrinking inward

```cpp
int num = 1;
int top = 0, bottom = n-1, left = 0, right = n-1;

while (top <= bottom && left <= right) {
    // Right
    for (int j = left; j <= right; j++) {
        matrix[top][j] = num++;
    }
    top++;
    
    // Down
    for (int i = top; i <= bottom; i++) {
        matrix[i][right] = num++;
    }
    right--;
    
    // Left (if row exists)
    if (top <= bottom) {
        for (int j = right; j >= left; j--) {
            matrix[bottom][j] = num++;
        }
        bottom--;
    }
    
    // Up (if column exists)
    if (left <= right) {
        for (int i = bottom; i >= top; i--) {
            matrix[i][left] = num++;
        }
        left++;
    }
}
```

---

## Problem-Solving Strategy

### Step 1: Understand the Pattern
- What makes it special?
- Is there a formula?
- What changes row by row?

### Step 2: Identify the Algorithm
- Prime checking?
- Sequence generation?
- Mathematical formula?

### Step 3: Combine Pattern + Algorithm
- Generate values first (if needed)
- Use triangle/grid structure
- Fill with computed values

### Step 4: Handle Edge Cases
- n=1 should work
- Large n shouldn't overflow
- Test thoroughly

---

## Implementation Checklist

- [ ] Basic pattern structure understood
- [ ] Algorithm (primes/Fibonacci/etc.) working
- [ ] Integration tested
- [ ] Edge cases handled
- [ ] Output verified

---

## Common Mistakes

❌ **Mixing pattern and algorithm**
- Build algorithm first
- Then apply to pattern structure

❌ **Integer overflow**
- Fibonacci grows fast
- Pascal's triangle values large
- Use `long long` when needed

❌ **Inefficient prime checking**
- Check divisibility up to sqrt(n)
- Cache primes if checking many

❌ **Off-by-one in sequences**
- Floyd: counter increments for each element
- Fibonacci: array indices careful
- Verify manually

---

## Tips and Tricks

✅ **Separate concerns**
```cpp
// Step 1: Generate sequence
vector<int> getSequence(int count) { ... }

// Step 2: Print in pattern
for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
        cout << sequence[idx++] << " ";
    }
    cout << "\n";
}
```

✅ **Pre-compute when possible**
- Generate all primes needed upfront
- Generate Fibonacci sequence first
- Then use in pattern

✅ **Test sequence independently**
- Before using in pattern
- Verify correctness
- Then integrate

✅ **Start with simple case**
- n=3 or n=4
- Verify manually
- Scale up

---

## Problem Summary

| Pattern | Difficulty | Key Algorithm |
|---------|-----------|---------------|
| Floyd | ⭐ | Counter |
| Pascal | ⭐⭐ | Combination formula |
| Prime | ⭐⭐ | Prime checking |
| Fibonacci | ⭐⭐ | Sequence generation |
| Spiral | ⭐⭐⭐ | Boundary tracking |

---

## What You Should Know

After Day 19, you should:
- ✅ Know Floyd's Triangle cold
- ✅ Understand Pascal's Triangle concept
- ✅ Implement efficient prime checking
- ✅ Generate Fibonacci sequences
- ✅ Solve 2D spiral problems

---

## Interview Prep

These patterns appear frequently:
- **Floyd's Triangle** → "Print triangle" question
- **Prime Pattern** → "Combine pattern + algorithm"
- **Spiral** → "Fill matrix in spiral"

Master these!

---

## Next Steps

Day 20: Mastery Review
- Capstone projects
- Real application
- Final challenges
- PHASE 1 complete!
