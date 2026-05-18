# 📝 Day 24: Searching & Insertion - Advanced Search Patterns

## Core Concepts

### When Linear Search is Enough
- Unsorted arrays
- Small arrays (< 1000 elements)
- Single pass required
- **Complexity:** O(n)

### When Binary Search is Better
- Sorted arrays
- Searching multiple times
- Large datasets
- **Complexity:** O(log n) — 1000x faster for n=10^6

### Key Patterns

#### 1. First Occurrence (Leftmost)
```cpp
for (int i = 0; i < n; i++) {
    if (arr[i] == target) {
        return i;  // Break on first match
    }
}
```

#### 2. Last Occurrence (Rightmost)
```cpp
for (int i = n - 1; i >= 0; i--) {
    if (arr[i] == target) {
        return i;  // Break on first match from right
    }
}
// OR: Keep updating result
int result = -1;
for (int i = 0; i < n; i++) {
    if (arr[i] == target) result = i;
}
```

#### 3. Binary Search Variations
**Find First:**
```cpp
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
        result = mid;
        right = mid - 1;  // Keep searching LEFT
    } else if (arr[mid] < target) {
        left = mid + 1;
    } else {
        right = mid - 1;
    }
}
```

**Find Last:**
```cpp
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
        result = mid;
        left = mid + 1;  // Keep searching RIGHT
    } else if (arr[mid] < target) {
        left = mid + 1;
    } else {
        right = mid - 1;
    }
}
```

#### 4. Rotated Array Search
```cpp
// Key insight: One half is ALWAYS sorted!
if (arr[left] <= arr[mid]) {
    // Left half is sorted
    if (target >= arr[left] && target < arr[mid]) {
        right = mid - 1;
    } else {
        left = mid + 1;
    }
} else {
    // Right half is sorted
    if (target > arr[mid] && target <= arr[right]) {
        left = mid + 1;
    } else {
        right = mid - 1;
    }
}
```

#### 5. Exponential Search (Unknown Size)
```cpp
// Find boundary
int bound = 1;
while (arr[bound] < target) {
    bound *= 2;
}
// Then binary search in [bound/2, bound]
```

---

## Complexity Comparison

| Operation | Linear | Binary | Exponential |
|-----------|--------|--------|-------------|
| Unsorted | O(n) | N/A | O(n) |
| Sorted | O(n) | O(log n) | O(log n) |
| Unknown Size | O(n) | N/A | O(log n) |
| Rotated | O(n) | O(log n) | N/A |

---

## Common Mistakes

1. **Off-by-one errors in binary search**
   - Wrong: `left = 0, right = n` (includes n, will be OOB)
   - Right: `left = 0, right = n-1` or use different termination

2. **Not checking if element exists**
   - Always return -1 if not found, not uninitialized value

3. **Forgetting mid-calculation overflow**
   - Wrong: `mid = (left + right) / 2`
   - Right: `mid = left + (right - left) / 2`

4. **Confusing first vs last occurrence in binary search**
   - First: Move right boundary LEFT after finding
   - Last: Move left boundary RIGHT after finding

---

## Problem Patterns

### Pattern 1: Basic Occurrence
- Find first, last, count occurrences
- Use linear search for unsorted, binary for sorted

### Pattern 2: Modified Array Search
- Rotated arrays, shifted arrays
- Identify sorted half, then decide direction

### Pattern 3: Unknown/Infinite Array
- Use exponential to find bounds
- Then binary search in bounds

### Pattern 4: Insert/Update Position
- Find where element should go
- Equivalent to lower_bound/upper_bound

---

## Interview Tips

**"I'll start with O(n) linear search, but notice the array is sorted,
so we can optimize to O(log n) with binary search!"**

**Rotated array:** "The key insight is one half is always sorted,
so we can identify which half contains target."**

**Unknown size:** "We can use exponential search to find the boundary,
then binary search within that boundary."**

---

## Variations to Consider

1. **Duplicates allowed?** → Affects first/last boundary search
2. **Array sorted ascending or descending?** → Adjust comparisons
3. **Can we modify array?** → Allows marking visited elements
4. **Multiple queries?** → Consider preprocessing (binary search tree, hash map)
5. **Very large array?** → Consider approximate algorithms
