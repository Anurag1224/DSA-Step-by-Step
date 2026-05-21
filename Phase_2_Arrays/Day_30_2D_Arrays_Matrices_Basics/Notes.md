# 📝 Day 30: 2D Arrays & Matrices (Basics) - Notes

## Key Patterns

### Pattern 1: Basic Traversals
```cpp
// Row-wise
for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
        // Process matrix[i][j]
    }
}

// Column-wise
for (int j = 0; j < n; j++) {
    for (int i = 0; i < m; i++) {
        // Process matrix[i][j]
    }
}

// Diagonal (top-left to bottom-right)
for (int i = 0; i < m; i++) {
    for (int j = 0; j < n && i + j < m + n; j++) {
        // Process matrix[i][j]
    }
}
```

---

### Pattern 2: Matrix Rotation (90° Clockwise)
```cpp
// Step 1: Transpose
for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
        swap(matrix[i][j], matrix[j][i]);
    }
}

// Step 2: Reverse each row
for (int i = 0; i < n; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
}
```

---

### Pattern 3: Layer-Based Processing
```cpp
// Process matrix in concentric layers
int top = 0, bottom = m - 1, left = 0, right = n - 1;

while (top <= bottom && left <= right) {
    // Process top row: [top, left] to [top, right]
    // Process right col: [top+1, right] to [bottom, right]
    // Process bottom row: [bottom, right] to [bottom, left]
    // Process left col: [bottom-1, left] to [top+1, left]
    
    top++; bottom--; left++; right--;
}
```

---

## Complexity Analysis

| Operation | Time | Space |
|-----------|------|-------|
| Traverse | O(m*n) | O(1) |
| Rotate 90° | O(m*n) | O(1) |
| Transpose | O(m*n) | O(1) |
| Spiral | O(m*n) | O(1) |

---

## Common Mistakes

1. **Indexing:** Remember (row, col) indexing
2. **Boundaries:** Check m*n division correctly
3. **In-place:** Careful with rotation to avoid overwrite
4. **Direction:** Clockwise vs counter-clockwise

---

## Interview Tips

✅ **Visualize:** Draw the matrix transformation  
✅ **Rotation:** Transpose + reverse is elegant  
✅ **Boundaries:** Layer approach handles edges well  
✅ **Follow-up:** How about 90° counter-clockwise?  

---

## When to Use

- Matrix element access patterns
- In-place transformations
- Traversal problems
- Coordinate transformations

---

## Memory Layout Considerations

- Row-major vs column-major (affects cache)
- In-place modifications affect original
- Transpose doesn't need extra space
- Layer iteration better than nested loops for some cases
