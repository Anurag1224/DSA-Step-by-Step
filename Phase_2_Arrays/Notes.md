# 📝 PHASE 2: Arrays - Key Concepts

## Array Fundamentals

### Why Arrays Matter
Arrays are the building blocks of optimization. Everything else (hash maps, heaps, graphs) is built on top.

### Memory Layout
- Contiguous memory: O(1) access by index
- Cache-friendly: sequential access is fast
- Fixed size (in C++): declared at creation

---

## Core Techniques in This Phase

### 1. Two Pointers
**When:** Searching pairs, removing duplicates, reversing
```cpp
int left = 0, right = n - 1;
while (left < right) {
    if (condition) {
        // Process pair
    }
    left++;
    right--;
}
```

### 2. Sliding Window
**When:** Substring problems, max/min in window, frequency
```cpp
int left = 0;
for (int right = 0; right < n; right++) {
    // Add arr[right] to window
    while (window_condition) {
        // Remove arr[left] from window
        left++;
    }
    // Process [left, right]
}
```

### 3. Prefix Sum
**When:** Range sum queries, cumulative operations
```cpp
vector<int> prefix(n + 1, 0);
for (int i = 0; i < n; i++) {
    prefix[i + 1] = prefix[i] + arr[i];
}
// Sum from index L to R: prefix[R+1] - prefix[L]
```

### 4. Two Pointers Meeting
**When:** Sorted array, finding pairs
```cpp
sort(arr.begin(), arr.end());
int left = 0, right = n - 1;
while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == target) {
        return {left, right};
    } else if (sum < target) {
        left++;
    } else {
        right--;
    }
}
```

---

## Complexity Expectations

| Problem Type | Brute Force | Optimized | Technique |
|--------------|------------|-----------|-----------|
| Max in range | O(n) per query | O(1) | Prefix max |
| Sum in range | O(n) per query | O(1) | Prefix sum |
| Two sum | O(n²) | O(n) | Hash map |
| Two sum (sorted) | O(n²) | O(n) | Two pointers |
| Duplicate removal | O(n²) | O(n) | Two pointers (sorted) |
| Subarray match | O(n²) | O(n) | Sliding window |
| Product subarray | O(n²) | O(n) | Sliding window |

---

## Array Pitfalls

### Integer Overflow
```cpp
// ❌ Can overflow
int sum = 0;
for (int x : arr) sum += x;

// ✅ Safe
long long sum = 0;
for (int x : arr) sum += x;
```

### Off-by-One Errors
```cpp
// ❌ Goes out of bounds
for (int i = 0; i <= n; i++) arr[i];

// ✅ Correct
for (int i = 0; i < n; i++) arr[i];
```

### Modifying While Iterating
```cpp
// ❌ Dangerous: modifying array during iteration
for (int i = 0; i < n; i++) {
    if (condition) arr.erase(arr.begin() + i);
}

// ✅ Better: use two pointers to modify in-place
int j = 0;
for (int i = 0; i < n; i++) {
    if (valid(arr[i])) {
        arr[j++] = arr[i];
    }
}
```

### Not Handling Duplicates
```cpp
// ❌ Assumes all unique
int secondMax = INT_MIN;
if (arr[i] > firstMax) {
    secondMax = firstMax;
    firstMax = arr[i];
} else {
    secondMax = arr[i];  // Wrong! Might be equal to firstMax
}

// ✅ Check distinctness
if (arr[i] > firstMax) {
    secondMax = firstMax;
    firstMax = arr[i];
} else if (arr[i] > secondMax && arr[i] != firstMax) {
    secondMax = arr[i];
}
```

---

## Interview Approach for Arrays

### Step 1: Understand & Clarify
- Are elements sorted?
- Can array be modified?
- What about duplicates?
- Constraints on space/time?

### Step 2: Brute Force First
- Simple nested loop solution
- O(n²) or O(n³) is okay initially
- Correctness over speed

### Step 3: Identify Optimization
- Can I use sorting? (Two pointers)
- Can I use prefix? (Range queries)
- Can I use sliding window? (Substrings/subarrays)
- Can I use hash map? (Frequency/pairs)

### Step 4: Implement & Test
- Edge cases: empty, single element, duplicates
- Boundary conditions: first, last, middle
- Overflow: use appropriate data types

### Step 5: Optimize Further
- Space optimization: in-place modifications
- Time optimization: better algorithm

---

## Real-World Applications

### Social Networks
- Find mutual friends (two pointers on sorted lists)
- Calculate engagement metrics (prefix sum)

### E-commerce
- Price range queries (prefix sum)
- Find similar priced items (two pointers)

### Data Analysis
- Moving averages (sliding window)
- Find anomalies (subarray sums)

---

## Day-by-Day Progression

**Days 21-22:** Basics and foundation  
**Days 23-24:** Two pointers mastery  
**Days 25-26:** Prefix sum patterns  
**Days 27-29:** Sliding window patterns  
**Days 30-35:** 2D arrays and subarrays  
**Days 36-43:** Complex patterns  
**Days 44-45:** Interview problems & review  

---

**This phase teaches you that optimization isn't magic — it's recognizing patterns and applying the right technique! 🎨**
