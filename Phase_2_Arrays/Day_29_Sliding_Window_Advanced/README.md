# 📖 Day 29: Sliding Window Advanced

**Complex sliding window: Multiple conditions, complex optimization.**

---

## Concepts Covered

### 1. Multiple Conditions
Combine several constraints in sliding window.

### 2. Complex Frequency Tracking
Compare window frequency with target frequency.

### 3. Optimization Patterns
Use sliding window to optimize DP or greedy.

---

## Problems Summary

| # | Problem | Difficulty | Key Concept |
|---|---------|-----------|------------|
| 1 | Permutation in String | ⭐⭐ Medium | Freq comparison |
| 2 | Substring Concatenation | ⭐⭐⭐ Hard | Word groups |
| 3 | At Most K Distinct | ⭐⭐ Medium | At most condition |
| 4 | Exactly K Distinct | ⭐⭐ Medium | Difference trick |
| 5 | Max Consecutive Ones | ⭐⭐ Medium | Ones + flips |
| 6 | Minimum Operations | ⭐⭐⭐ Hard | Shrink optimization |

---

## Key Insights

1. **Frequency Equality:** Compare full maps, not just size
2. **Difference Trick:** atMost(k) - atMost(k-1) = exactly k
3. **No Left Shrink:** Sometimes never shrink, just count
4. **Optimization:** Sliding window often beats DP

---

## Interview Readiness

✅ **Recognize Pattern:** When sliding window applies  
✅ **Edge Cases:** Empty, all same, very long strings
