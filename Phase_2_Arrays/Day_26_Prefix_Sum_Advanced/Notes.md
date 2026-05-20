# 📝 Day 26: Prefix Sum Advanced - Notes

## Key Patterns

### Pattern 1: 2D Prefix Sum
```cpp
for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
        prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] 
                       - prefix[i-1][j-1] + matrix[i-1][j-1];
    }
}
// Query: sum = prefix[r2+1][c2+1] - prefix[r1][c2+1] 
//             - prefix[r2+1][c1] + prefix[r1][c1]
```
**Visualization:** Inclusion-exclusion with 4 corners

---

### Pattern 2: XOR Prefix Properties
```cpp
// XOR Properties:
// a ⊕ a = 0 (self-cancel)
// a ⊕ 0 = a (identity)
// prefix[i] ⊕ prefix[j] = XOR of subarray[j+1...i]
// If prefix[i] ⊕ target = prefix[j], subarray has XOR = target
```

---

### Pattern 3: Sparse Data Optimization
- Use prefix sums for range queries
- Index compression for large ranges
- Segment trees for updates

---

## Complexity Comparison

| Technique | Build | Query | Update | Space |
|-----------|-------|-------|--------|-------|
| 1D Prefix | O(n) | O(1) | O(n) | O(n) |
| 2D Prefix | O(m*n) | O(1) | O(m*n) | O(m*n) |
| Segment Tree | O(n) | O(log n) | O(log n) | O(n) |
| Fenwick Tree | O(n) | O(log n) | O(log n) | O(n) |

---

## Common Mistakes

1. **Indexing Confusion:** 1-indexed prefix vs 0-indexed matrix
2. **Order of Operations:** Inclusion-exclusion order matters
3. **XOR Overflow:** Handle negative remainders in modulo
4. **Query Range:** Off-by-one errors in rectangle boundaries

---

## Interview Tips

✅ **2D Extension:** Naturally extends from 1D  
✅ **Space-Time:** Trading O(m*n) space for O(1) queries  
✅ **Follow-up:** Can we handle point updates? (Segment tree)  
✅ **Optimization:** Pre-compute if many queries expected  

---

## When to Use

- Multiple 2D range queries needed
- Immutable matrix (no updates)
- Large query volume, small matrix
- Building blocks for advanced problems
