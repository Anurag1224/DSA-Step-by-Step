# 📖 Day 23: Two Pointers - Part 1

**Meeting in the Middle: The Foundation of Array Optimization**

---

## Concepts Covered

### 1. Two Pointer Pattern
Start from opposite ends and move towards each other based on conditions.

```cpp
int left = 0, right = n - 1;
while (left < right) {
    if (condition) {
        // Process or update
    }
    left++;   // or left-- depending on logic
    right--;  // or right++ depending on logic
}
```

### 2. When to Use Two Pointers
- Sorted arrays (most common)
- Palindrome checking
- Container problems (max area/width)
- Finding pairs with specific sum

### 3. Key Insights
- **Move the smaller pointer**: If trying to increase sum, move left. If decrease, move right.
- **In-place modification**: Use one pointer for read, one for write
- **Backward filling**: Sometimes fill result array backwards for sorted order

---

## Problems Summary

| Problem | Pattern | Use Case |
|---------|---------|----------|
| 01_two_sum | Meeting pointers | Pair finding |
| 02_valid_palindrome | Skip non-alphanum | String validation |
| 03_remove_duplicates | Read-write pointer | In-place modification |
| 04_container_water | Greedy movement | Area maximization |
| 05_merge_arrays | Merge sorted | Combining data |
| 06_squares_sorted | Backward fill | Negative handling |

---

## Two Pointer Variations

### Pattern 1: Meeting from Ends
```cpp
int left = 0, right = n - 1;
while (left < right) {
    // Process and move towards center
    left++;
    right--;
}
```

### Pattern 2: One Moving (In-place)
```cpp
int j = 0;
for (int i = 1; i < n; i++) {
    if (condition) {
        arr[j++] = arr[i];
    }
}
// j is the length of modified array
```

### Pattern 3: Merge Two Arrays
```cpp
int i = 0, j = 0, k = 0;
while (i < m && j < n) {
    if (arr1[i] <= arr2[j]) {
        result[k++] = arr1[i++];
    } else {
        result[k++] = arr2[j++];
    }
}
// Add remaining from either array
```

---

## Interview Tips

1. **Always clarify**: Is the array sorted? Can we modify it?
2. **Start simple**: Draw out the two pointer movements
3. **Greedy intuition**: Why move this pointer instead of that?
4. **Edge cases**: Single element, all same, mixed negatives

---

## Common Mistakes

❌ Moving both pointers in same direction  
❌ Not skipping non-relevant elements (palindrome)  
❌ Forgetting to add remaining elements (merge)  
❌ Filling forward instead of backward (squares)  
❌ Not updating pointer when found  

✅ Move towards center or based on condition  
✅ Explicitly skip non-alphanumeric/non-valid elements  
✅ Always add remaining elements from both arrays  
✅ Fill backward when ordering matters  
✅ Update pointer before next iteration  

---

## Complexity Summary

| Problem | Time | Space | Notes |
|---------|------|-------|-------|
| Two Sum | O(n) | O(1) | Requires sorted |
| Palindrome | O(n) | O(1) | Skip non-alphanum |
| Remove Duplicates | O(n) | O(1) | In-place |
| Container Water | O(n) | O(1) | Greedy pointer move |
| Merge Arrays | O(m+n) | O(m+n) | Standard merge |
| Squares | O(n) | O(n) | Backward filling |

All **O(n) time** — the power of two pointers!

---

## What's Next?

Day 24: **Two Pointers - Part 2** — Advanced patterns and more complex conditions

---

**Two pointers are your secret weapon for array optimization! ⚡**
