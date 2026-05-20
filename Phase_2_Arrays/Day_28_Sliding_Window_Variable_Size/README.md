# 📖 Day 28: Sliding Window (Variable Size)

**Expanding and contracting window for complex conditions.**

---

## Concepts Covered

### 1. Variable Window Pattern
Expand right to add elements, shrink left when condition met.

```cpp
int left = 0;
for (int right = 0; right < n; right++) {
    // Add arr[right] to window
    
    while (condition) {
        // Remove arr[left] and shrink
        left++;
    }
    
    // Process [left, right]
}
```

### 2. Conditions
- Min window with property
- Longest subarray with constraint
- Shortest subarray with target

### 3. Frequency Tracking
Count character frequencies, track needed vs current.

---

## Problems Summary

| # | Problem | Difficulty | Key Concept |
|---|---------|-----------|------------|
| 1 | Min Window Substring | ⭐⭐⭐ Hard | Frequency map |
| 2 | Longest Substring No Repeat | ⭐⭐ Medium | Char position map |
| 3 | Longest Subarray K Distinct | ⭐⭐ Medium | Hash map |
| 4 | Shortest Subarray Sum | ⭐⭐⭐ Hard | Shrink condition |
| 5 | Permutation in String | ⭐⭐ Medium | Window comparison |
| 6 | Substring Concatenation | ⭐⭐⭐ Hard | Word frequency |

---

## Key Insights

1. **Two Conditions:** Often need 2 phases (expand + shrink)
2. **Frequency Map:** Track what we need vs what we have
3. **Valid State:** Know when window is valid/invalid
4. **Optimize:** Shrink before expanding next iteration

---

## Interview Readiness

✅ **Pattern Recognition:** When to use variable window  
✅ **State Tracking:** What to store in window
