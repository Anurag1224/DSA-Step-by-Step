# 📖 Day 22: Linear Search & Sorting Prep

**When Linear Search Fails: Binary Search is Born**

---

## Concepts Covered

### 1. Why Sorting Matters
- Linear search: O(n) on unsorted array
- Binary search: O(log n) on sorted array
- Difference grows exponentially with size

### 2. Binary Search Template
```cpp
int left = 0, right = n - 1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        left = mid + 1;
    } else {
        right = mid - 1;
    }
}
return -1;  // Not found
```

### 3. Finding Boundaries
- **First occurrence**: Search left after finding
- **Last occurrence**: Search right after finding
- **Floor**: Largest number ≤ target
- **Ceiling**: Smallest number ≥ target

### 4. Insertion Position
- Where to place element to maintain sorted order
- Essentially finding ceiling position

---

## Problems Summary

| Problem | Pattern | Use Case |
|---------|---------|----------|
| 01_binary_search_first | Find first | Duplicate handling |
| 02_binary_search_last | Find last | Count occurrences |
| 03_count_binary_search | Combine first+last | Frequency queries |
| 04_floor_value | Largest ≤ target | Range queries |
| 05_ceiling_value | Smallest ≥ target | Nearest neighbor |
| 06_insert_position | Where to insert | Sorted insertion |

---

## Key Binary Search Patterns

### Standard Binary Search
```cpp
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) left = mid + 1;
    else right = mid - 1;
}
```

### Finding First Occurrence
```cpp
int result = -1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
        result = mid;
        right = mid - 1;  // Keep searching left
    } else if (arr[mid] < target) left = mid + 1;
    else right = mid - 1;
}
```

### Floor Value (≤ target)
```cpp
int result = -1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] <= target) {
        result = arr[mid];
        left = mid + 1;  // Search right for larger
    } else right = mid - 1;
}
```

### Insertion Position
```cpp
int left = 0, right = n;  // Important: right = n
while (left < right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] < target) left = mid + 1;
    else right = mid;
}
// left is the insertion position
```

---

## Interview Tips

1. **Always check if array is sorted** — Binary search only works on sorted arrays
2. **Avoid integer overflow** — Use `mid = left + (right - left) / 2`
3. **Think about boundaries** — Do you want first, last, floor, or ceiling?
4. **Edge cases** — Empty array, single element, all smaller/larger than target

---

## Complexity Comparison

| Operation | Linear Search | Binary Search |
|-----------|---|---|
| Find element | O(n) | O(log n) |
| Find first | O(n) | O(log n) |
| Find last | O(n) | O(log n) |
| Count | O(n) | O(log n) |

For n = 10^5:
- Linear: ~100,000 operations
- Binary: ~17 operations

---

## Common Mistakes

❌ Forgetting array must be sorted  
❌ Using `mid = (left + right) / 2` (can overflow)  
❌ Not updating result before continuing search  
❌ Confusing first vs last occurrence logic  
❌ Using `right = n-1` when need `right = n`  

✅ Always check if sorted first  
✅ Use `mid = left + (right - left) / 2`  
✅ Store result, keep searching  
✅ First: `right = mid - 1`, Last: `left = mid + 1`  
✅ Insertion position: `right = n`  

---

## What's Next?

Day 23: **Two Pointers (Part 1)** — Meeting in the middle

---

**Binary search transforms O(n) into O(log n) — master this! ⚡**
