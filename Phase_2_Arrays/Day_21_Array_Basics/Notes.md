# 📝 Day 21: Array Basics - Quick Notes

## Critical Points

### Always Use Long Long for Sums
```cpp
// ❌ Wrong: overflow with large numbers
int sum = 0;
for (int x : arr) sum += x;

// ✅ Correct: prevents overflow
long long sum = 0;
for (int x : arr) sum += x;
```

### Initialize Max/Min Safely
```cpp
// ❌ Risky: INT_MIN might cause issues
int maxElement = INT_MIN;

// ✅ Safe: guaranteed to work
int maxElement = arr[0];
```

### Early Exit in Linear Search
```cpp
// ❌ Wasteful: checks all remaining elements
for (int i = 0; i < n; i++) {
    if (arr[i] == target) {
        count++;  // Keep searching
    }
}

// ✅ Efficient: return as soon as found
for (int i = 0; i < n; i++) {
    if (arr[i] == target) {
        cout << i << "\n";
        return 0;  // Stop here
    }
}
```

### Two Pointer Reversal
```cpp
int left = 0, right = n - 1;
while (left < right) {
    swap(arr[left], arr[right]);
    left++;
    right--;
}
// Time: O(n), Space: O(1)
```

### Tracking Multiple Maximums
```cpp
// For second largest, maintain TWO variables
int largest = INT_MIN, secondLargest = INT_MIN;
for (int i = 0; i < n; i++) {
    if (arr[i] > largest) {
        secondLargest = largest;  // OLD largest → new second
        largest = arr[i];
    } else if (arr[i] > secondLargest && arr[i] != largest) {
        secondLargest = arr[i];
    }
}
```

---

## Interview Common Questions

Q: "Can you solve it in O(1) space?"  
A: Yes, most array problems can be solved with O(1) space using two pointers or in-place modifications.

Q: "How do you handle overflow?"  
A: Use `long long` for arithmetic operations. Check constraints first.

Q: "What if array is sorted?"  
A: Then use binary search (O(log n)) instead of linear search (O(n)).

---

## Gotchas

- **Index out of bounds**: Always check `0 ≤ i < n`
- **Integer overflow**: Sum and products need `long long`
- **Duplicates**: Don't assume all elements are unique
- **Negative numbers**: Works with negatives too
- **Single element**: Should return that element itself

---

## Problem Patterns to Recognize

| Pattern | Example | Technique |
|---------|---------|-----------|
| **Find extremum** | Max, min, second-largest | Single/dual pass |
| **Linear search** | Find index of element | Conditional loop |
| **Transform in-place** | Reverse, rotate | Two pointers |
| **Count/aggregate** | Sum, count, average | Accumulator |

---

**Next: Sorting and binary search will unlock optimization patterns! 🚀**
