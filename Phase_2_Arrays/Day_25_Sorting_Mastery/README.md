# Day 25: Sorting Mastery 🚀

## Learning Goals
- [ ] Understand all major sorting algorithms deeply
- [ ] Compare O(n²) vs O(n log n) trade-offs
- [ ] Know when to use each algorithm
- [ ] Implement merge sort (guaranteed O(n log n))
- [ ] Implement quick sort (fastest average case)
- [ ] Master custom comparators for sorting
- [ ] Understand stability and when it matters

## Problems

| # | Problem | Difficulty | Algorithm | Complexity |
|---|---------|-----------|-----------|-----------|
| 1 | Bubble Sort | ⭐ Easy | O(n²) | Educational |
| 2 | Selection Sort | ⭐ Easy | O(n²) | Minimal writes |
| 3 | Insertion Sort | ⭐ Easy | O(n²) | Best practical O(n²) |
| 4 | Merge Sort | ⭐⭐ Medium | O(n log n) | Guaranteed, stable |
| 5 | Quick Sort | ⭐⭐ Medium | O(n log n) avg | Fastest average |
| 6 | Custom Comparators | ⭐⭐ Medium | Depends | Multiple criteria |

## Key Concepts

### O(n²) Sorting (When data < 1000 elements)
- **Bubble:** Many comparisons AND swaps (worst)
- **Selection:** Many comparisons, FEW swaps (best for limited I/O)
- **Insertion:** Adaptive to partially sorted data (best practical O(n²))

### O(n log n) Sorting (Production code)
- **Merge:** Guaranteed, stable, but requires O(n) space
- **Quick:** Fastest average, in-place, but not stable
- **Hybrid:** Real libraries use combinations

### Custom Sorting
```cpp
// By second element of pair
sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
    return a.second < b.second;
});

// By multiple criteria
sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
    if (a.field1 != b.field1) return a.field1 < b.field1;
    return a.field2 > b.field2;  // Different order for second
});
```

## Solution Complexity Breakdown

```
Problem 1-3: O(n²) — Educational, understand concepts
Problem 4: O(n log n) — Best for guaranteed performance
Problem 5: O(n log n) avg — Best for speed (but O(n²) worst)
Problem 6: O(n log n) — Same as underlying sort
```

## Key Takeaways

1. **Bubble Sort:** Never use in production (educational only)
2. **Selection Sort:** Use when minimizing writes is critical
3. **Insertion Sort:** Best O(n²) algorithm, good for small/online data
4. **Merge Sort:** Use when O(n log n) guaranteed, stability needed
5. **Quick Sort:** Use for general-purpose sorting (fastest average)
6. **Stability:** Matters for multi-field sorting or secondary keys

## Common Patterns

### Problem: Sort pairs by second element
```cpp
sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
    return a.second < b.second;
});
```

### Problem: Sort descending then ascending by tiebreaker
```cpp
sort(arr.begin(), arr.end(), [](const auto& a, const auto& b) {
    if (a.priority != b.priority) return a.priority > b.priority;
    return a.index < b.index;
});
```

### Problem: Sort custom objects
```cpp
sort(objects.begin(), objects.end(), [](const Object& a, const Object& b) {
    return a.value < b.value;
});
```

## Interview Readiness

✅ Can implement all major sorting algorithms
✅ Can analyze and compare complexities
✅ Can choose appropriate algorithm for scenario
✅ Can write custom comparators
✅ Can optimize pivot selection (Quick Sort)
✅ Can explain stability and when it matters
✅ Know what real libraries use (std::sort, Tim Sort)

## Real-World Application

- **Databases:** Use Merge Sort variants (guaranteed time, stability)
- **Competitive Programming:** Use Quick Sort (fastest average)
- **Real-time Systems:** Use Merge Sort (predictable O(n log n))
- **Nearly Sorted Data:** Use Insertion Sort (O(n) best case)
- **Hybrid Sorting:** Libraries use quick sort + insertion sort + heap sort

## Next Steps

- Day 26: Sliding Window Part 1 (contiguous subarrays)
- Day 27: Sliding Window Part 2 (variable window)
- Day 28: Prefix Sum Techniques
