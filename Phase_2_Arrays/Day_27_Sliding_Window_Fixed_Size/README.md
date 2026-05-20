# 📖 Day 27: Sliding Window (Fixed Size)

**Window of constant size, efficient element addition/removal.**

---

## Concepts Covered

### 1. Fixed Window Pattern
Move window right, and remove leftmost when window overflows.

```cpp
int left = 0;
for (int right = 0; right < n; right++) {
    // Add arr[right] to window
    
    if (right - left + 1 > k) {  // Window too large
        // Remove arr[left] from window
        left++;
    }
    
    // Process [left, right]
}
```

### 2. Window Maximum/Minimum
Track max/min in sliding window efficiently (deque-based).

### 3. Sum of Windows
Calculate sum of all windows of size k.

---

## Problems Summary

| # | Problem | Difficulty | Key Concept |
|---|---------|-----------|------------|
| 1 | Sliding Window Max | ⭐⭐ Medium | Deque, maintain order |
| 2 | Max Avg Subarray | ⭐⭐ Easy | Simple sliding window |
| 3 | Contains Duplicate II | ⭐⭐ Easy | Set size check |
| 4 | Longest Repeating | ⭐⭐ Medium | Window + freq |
| 5 | Number of Subarrays | ⭐⭐ Medium | Count windows |
| 6 | Grumpy Bookstore | ⭐⭐ Medium | Window optimization |

---

## Key Insights

1. **Fixed Size:** Simpler pattern, just slide
2. **Deque for Min/Max:** Maintain indices, pop obsolete
3. **Early Termination:** Often not applicable
4. **Space Optimization:** Deque space vs array space

---

## Interview Readiness

✅ **Pattern:** Always sliding window fixed size?  
✅ **Follow-up:** What if size varies?
