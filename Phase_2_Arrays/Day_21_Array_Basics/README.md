# 📖 Day 21: Array Basics (Traversal & Indexing)

**Warmup day. Master array fundamentals before optimization.**

---

## Concepts Covered

### 1. Array Traversal
Simple iteration through arrays. Foundation for everything.

```cpp
for (int i = 0; i < n; i++) {
    // Process arr[i]
}
```

### 2. Single Pass Solutions
Most problems can be solved in one iteration.

### 3. Keeping Track of State
Maintain variables for max, sum, count, etc.

### 4. Early Exit
When condition is found, return immediately.

---

## Problems Summary

| Problem | Concept | Pattern |
|---------|---------|---------|
| 01_array_sum | Sum all elements | Accumulation |
| 02_find_maximum | Find largest | Comparison |
| 03_linear_search | Find position | Conditional |
| 04_reverse_array | Reverse in-place | Two pointers |
| 05_count_occurrences | Count matches | Counter |
| 06_second_largest | Find 2nd max | State tracking |

---

## Key Learnings

### ✅ Overflow Prevention
```cpp
long long sum = 0;  // Not int!
```

### ✅ Initialization
```cpp
int maxElement = arr[0];  // Not INT_MIN!
```

### ✅ Early Return
```cpp
if (arr[i] == target) {
    cout << i << "\n";
    return 0;  // Stop searching
}
```

### ✅ Two Pointer Pattern
```cpp
int left = 0, right = n - 1;
while (left < right) {
    swap(arr[left], arr[right]);
    left++;
    right--;
}
```

---

## Interview Tips

1. **Always ask about constraints** — affects data types
2. **Handle edge cases first** — single element, duplicates
3. **One pass when possible** — O(n) is optimal
4. **Explain state tracking** — what variables are you maintaining?

---

## Complexity Summary

| Problem | Time | Space | Notes |
|---------|------|-------|-------|
| Array Sum | O(n) | O(1) | Use long long |
| Find Max | O(n) | O(1) | Initialize with arr[0] |
| Linear Search | O(n) | O(1) | Early exit if found |
| Reverse Array | O(n) | O(1) | In-place with two pointers |
| Count | O(n) | O(1) | Simple counter |
| Second Largest | O(n) | O(1) | Maintain two variables |

---

## Common Mistakes

❌ Using `int` for sum (overflow)  
❌ Initializing max with `INT_MIN` (risky)  
❌ Not returning when element found (wastes time)  
❌ Counting duplicates as largest (check `arr[i] != largest`)  
❌ Reversing with extra array (space inefficient)  

✅ Use `long long` for sums  
✅ Initialize with first element  
✅ Return early from search  
✅ Check distinctness when needed  
✅ Use two-pointer in-place reversal  

---

## What's Next?

Day 22: **Linear Search & Sorting Prep** — when sorted arrays matter

---

**Master these fundamentals before optimization. Fast code is worthless if it's wrong! 🎯**
