# 📝 Day 23: Two Pointers - Quick Notes

## Core Template

### Meeting from Ends
```cpp
int left = 0, right = n - 1;
while (left < right) {
    if (arr[left] + arr[right] == target) {
        // Found!
        return true;
    } else if (arr[left] + arr[right] < target) {
        left++;  // Need larger sum
    } else {
        right--;  // Need smaller sum
    }
}
```

### In-Place Modification
```cpp
int j = 0;
for (int i = 1; i < n; i++) {
    if (arr[i] != arr[j]) {
        j++;
        arr[j] = arr[i];
    }
}
return j + 1;  // Length
```

---

## Key Patterns

### Two Sum on Sorted Array
```cpp
// O(n) solution - much better than O(n²) hash map!
left = 0, right = n - 1
while left < right:
    if arr[left] + arr[right] == target: return (left, right)
    if arr[left] + arr[right] < target: left++
    else: right--
```

### Palindrome Checking
```cpp
Skip non-alphanumeric from both ends
Compare lowercase versions
Move inward if match
Return false if any mismatch
```

### In-Place Duplicate Removal
```cpp
j = 0 (write position)
for i = 1 to n:
    if arr[i] != arr[j]:
        j++
        arr[j] = arr[i]
return j + 1
```

### Container with Most Water
```cpp
Start from ends (maximum width)
area = min(height[left], height[right]) * (right - left)
Move the pointer with SMALLER height
(Taller pointer can't improve area if we move it)
```

### Merge Sorted Arrays
```cpp
Compare arr1[i] and arr2[j]
Add smaller to result
Move that pointer forward
Add remaining from whichever array is left
```

### Squares of Sorted Array (Negatives)
```cpp
Fill result BACKWARDS (right to left)
Compare squares from both ends
Pick larger square
Move corresponding pointer
Backward fill ensures sorted output!
```

---

## Mental Models

### Why Two Pointers Works

**For sorted array with two sum:**
- If sum too small: increasing left or decreasing right
  - Left increases sum (larger elements to right)
  - Right decreases sum (smaller elements to left)
- Only moving left helps when sum < target
- Only moving right helps when sum > target

**For in-place modification:**
- j tracks position to write
- i tracks position to read
- Write only when condition met
- Overwrites duplicates with unique elements

**For container water:**
- Maximum area always at max distance
- Moving taller pointer can't help (smaller height limits)
- Moving shorter pointer might find taller bar

---

## Complexity Breakdown

| Approach | Time | Space | Notes |
|----------|------|-------|-------|
| Two Sum (brute) | O(n²) | O(1) | Nested loops |
| Two Sum (two pointers) | O(n) | O(1) | Only sorted |
| Two Sum (hash map) | O(n) | O(n) | Works unsorted |
| Palindrome (two pointers) | O(n) | O(1) | Skip non-alphanum |
| Duplicates | O(n) | O(1) | In-place |
| Container | O(n) | O(1) | Greedy |
| Merge | O(m+n) | O(m+n) | All elements |

---

## Common Pitfalls & Fixes

| Mistake | Example | Fix |
|---------|---------|-----|
| Moving wrong pointer | Two Sum: always left++ | Check sum direction |
| Not skipping non-alphanum | Palindrome: compares spaces | Add skip loop |
| Forgetting remaining | Merge: missing arr2[j:] | Loop after main loop |
| Filling forward wrong | Squares: forward fill unsorted | Fill backward! |
| Wrong loop condition | while (left <= right) | Use < for meeting pointers |

---

## Interview Checklist

- [ ] Is the array sorted? (affects approach)
- [ ] Can we modify array? (affects in-place option)
- [ ] Two pointers applicable here?
- [ ] Start from ends or start?
- [ ] When do we move which pointer?
- [ ] Handle edge cases: empty, single element, all same
- [ ] Verify time/space complexity

---

**Two pointers are elegant, efficient, and interview favorites! Master them! 🎯**
