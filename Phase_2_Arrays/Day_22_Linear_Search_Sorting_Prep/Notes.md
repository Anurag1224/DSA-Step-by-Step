# 📝 Day 22: Binary Search - Quick Notes

## Binary Search Basics

### Overflow Prevention
```cpp
// ❌ Can overflow with large left and right
int mid = (left + right) / 2;

// ✅ Safe calculation
int mid = left + (right - left) / 2;
```

### Standard Template
```cpp
int left = 0, right = n - 1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) return mid;
    if (arr[mid] < target) left = mid + 1;
    else right = mid - 1;
}
return -1;
```

---

## Finding Specific Positions

### First Occurrence (Leftmost)
```cpp
int result = -1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
        result = mid;
        right = mid - 1;  // Search LEFT for earlier occurrence
    } else if (arr[mid] < target) left = mid + 1;
    else right = mid - 1;
}
```

### Last Occurrence (Rightmost)
```cpp
int result = -1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
        result = mid;
        left = mid + 1;  // Search RIGHT for later occurrence
    } else if (arr[mid] < target) left = mid + 1;
    else right = mid - 1;
}
```

### Count Occurrences
```cpp
int first = findFirst(arr, target);
if (first == -1) return 0;
int last = findLast(arr, target);
return last - first + 1;
```

---

## Floor and Ceiling

### Floor (≤ target) - Largest number ≤ target
```cpp
int result = -1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] <= target) {
        result = arr[mid];
        left = mid + 1;  // Try to find larger number
    } else right = mid - 1;
}
```

### Ceiling (≥ target) - Smallest number ≥ target
```cpp
int result = -1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] >= target) {
        result = arr[mid];
        right = mid - 1;  // Try to find smaller number
    } else left = mid + 1;
}
```

---

## Insertion Position

### Where to Insert to Keep Sorted
```cpp
int left = 0, right = n;  // Note: right = n, not n-1
while (left < right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] < target) left = mid + 1;
    else right = mid;
}
// left is the insertion position
```

**Key insight**: `left` stops at the first position where `arr[mid] >= target`

---

## Mental Model

Think of binary search as finding a **boundary**:
- **Standard**: Exact match
- **First**: Left boundary of duplicates
- **Last**: Right boundary of duplicates
- **Floor**: Largest element on the left side
- **Ceiling**: Smallest element on the right side
- **Insert**: Position where element fits

---

## Complexity Cheat Sheet

| Problem | Time | Space | Note |
|---------|------|-------|------|
| Standard binary search | O(log n) | O(1) | Must be sorted |
| First occurrence | O(log n) | O(1) | Keep going left |
| Last occurrence | O(log n) | O(1) | Keep going right |
| Count duplicates | O(log n) | O(1) | First + Last - 1 |
| Floor value | O(log n) | O(1) | Largest ≤ |
| Ceiling value | O(log n) | O(1) | Smallest ≥ |
| Insert position | O(log n) | O(1) | Where it fits |

---

## When Binary Search Fails

Binary search requires **sorted arrays**. If array is unsorted:
- **Option 1**: Sort first (O(n log n) total)
- **Option 2**: Use linear search (O(n))
- **Option 3**: Use hash map (O(n) space, O(1) lookup)

---

**Binary search is the superpower that transforms O(n) into O(log n)! 🚀**
