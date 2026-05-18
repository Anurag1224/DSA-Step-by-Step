# Day 24: Searching & Insertion 🔍

## Learning Goals
- [ ] Master linear search and when it's appropriate
- [ ] Understand binary search deeply (not just code it)
- [ ] Handle boundary conditions correctly
- [ ] Optimize search for different data distributions
- [ ] Recognize when to use which search technique
- [ ] Handle edge cases in search problems

## Problems

| # | Problem | Difficulty | Key Concept |
|---|---------|-----------|-------------|
| 1 | First Occurrence | ⭐ Easy | Break early, index tracking |
| 2 | Last Occurrence | ⭐ Easy | Right-to-left iteration |
| 3 | Count Occurrences | ⭐⭐ Medium | Binary search boundaries |
| 4 | Rotated Array Search | ⭐⭐ Medium | Identify sorted half |
| 5 | Insert Position | ⭐⭐ Medium | Lower bound concept |
| 6 | Unknown Size Search | ⭐⭐ Medium | Exponential + Binary |

## Solution Time Complexity

```
Problem 1-2: O(n) linear
Problem 3: O(n) naive, O(log n) optimized
Problem 4-6: O(log n) binary search variants
```

## Key Takeaways

1. **Linear Search:** O(n), simple, works for unsorted
2. **Binary Search:** O(log n), requires sorted, much faster
3. **Optimization:** Always ask "Can we sort first?" or "Is it already sorted?"
4. **Boundary Cases:** First/last occurrences need careful handling
5. **Rotated Arrays:** Leverage that one half is sorted
6. **Unknown Size:** Exponential search finds boundary efficiently

## Interview Readiness

✅ Can explain trade-offs between search algorithms
✅ Can implement binary search without off-by-one errors  
✅ Can optimize from O(n) to O(log n)
✅ Can handle rotated/shifted/unknown arrays
✅ Can identify and defend edge cases

## Next Steps

- Day 25: Sorting strategies and complexity analysis
- Day 26: Sliding window problems (contiguous subarrays)
- Day 27: Advanced sliding window (variable window size)
