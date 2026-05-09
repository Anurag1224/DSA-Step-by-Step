# 📝 DAY 16 Notes: Advanced Symmetry

## Key Concepts

### Rotational Symmetry

**Rotation** = spinning pattern 90°, 180°, 270°

#### 180-Degree Rotation
```
Original:          Rotated 180°:
*                     *
**                   **
***                 ***
```
- Upside down
- Same pattern, different orientation

#### Quadrant Division
Divide n×n grid into 4 quadrants:
```
Q1 | Q2
---+---
Q3 | Q4
```
- Use conditions to identify quadrant
- Apply different patterns per quadrant

---

## Advanced Symmetry Patterns

### Pattern 1: 180-Degree Rotation

```cpp
// Store top half
vector<string> lines;
for (int i = 1; i <= n; i++) {
    string line = "";
    for (int j = 0; j < i; j++) {
        line += "*";
    }
    lines.push_back(line);
}

// Print top half (centered)
for (auto& line : lines) {
    for (int j = 0; j < n - line.size(); j++) cout << " ";
    cout << line << "\n";
}

// Print bottom half (rotated)
for (int i = n-1; i >= 1; i--) {
    for (int j = 0; j < n - i; j++) cout << " ";
    for (int j = 0; j < i; j++) cout << "*";
    cout << "\n";
}
```

### Pattern 2: Four-Quadrant Division

```cpp
int mid = n / 2;
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        if (i < mid && j < mid) {
            cout << "A";  // Top-left
        } else if (i < mid && j >= mid) {
            cout << "B";  // Top-right
        } else if (i >= mid && j < mid) {
            cout << "C";  // Bottom-left
        } else {
            cout << "D";  // Bottom-right
        }
    }
    cout << "\n";
}
```

### Pattern 3: Triangular Grid

Diagonals form triangular patterns:
```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
        cout << (i + j + 1) % 10 << " ";
    }
    cout << "\n";
}
```

### Pattern 4: Diagonal Bands

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        cout << ((i + j) % 3) << " ";
    }
    cout << "\n";
}
```

Creates repeating bands along diagonals.

### Pattern 5: Double Reflection

Mirror pattern on both axes:
```cpp
// Left half
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        if (j == i || j == n - i - 1) {
            cout << "* ";
        } else {
            cout << "  ";
        }
    }
    cout << "| ";
    // Right half (mirror)
    for (int j = n - 1; j >= 0; j--) {
        if (j == i || j == n - i - 1) {
            cout << "* ";
        } else {
            cout << "  ";
        }
    }
    cout << "\n";
}
```

---

## Quadrant Logic Deep Dive

For n×n grid:
```
     0 ... mid ... n-1
  0  Q1      Q2
  .
mid  Q3      Q4
  .
n-1
```

Conditions:
- **Q1**: i < mid AND j < mid
- **Q2**: i < mid AND j >= mid
- **Q3**: i >= mid AND j < mid
- **Q4**: i >= mid AND j >= mid

Or based on distance from edges:
```cpp
int minDist = min({i, j, n-1-i, n-1-j});
```
Creates concentric patterns!

---

## Distance-Based Patterns

### Minimum Distance from Edge
```cpp
int dist = min({i, j, n-1-i, n-1-j});
cout << dist;
```

This creates concentric squares:
```
0 0 0 0 0
0 1 1 1 0
0 1 2 1 0
0 1 1 1 0
0 0 0 0 0
```

### Custom Distance Formulas
- Manhattan distance: |i-center| + |j-center|
- Chebyshev distance: max(|i-center|, |j-center|)
- Euclidean: sqrt((i-center)² + (j-center)²)

---

## Common Mistakes

❌ **Wrong quadrant conditions**
- Use AND (&&) for quadrant separation
- Not OR (||)
- `i < mid && j < mid` (correct)
- `i < mid || j < mid` (wrong)

❌ **Off-by-one in symmetry**
- 180° rotation: need full inversion
- Not just reversing one axis
- Check corners specifically

❌ **Distance calculation error**
- min/max of 4 values, not 2
- Don't forget (n-1-i) and (n-1-j)

❌ **Misunderstanding "symmetry"**
- Reflection ≠ Rotation
- Rotation ≠ Both axes mirror
- Define clearly before coding

---

## Tips and Tricks

✅ **Visualize on graph paper**
- Mark quadrants with colors
- Draw distance contours
- See pattern emerge

✅ **Test quadrant conditions**
```cpp
// Test each quadrant separately
int mid = n / 2;
if (i < mid && j < mid) cout << "Q1 ";
if (i < mid && j >= mid) cout << "Q2 ";
if (i >= mid && j < mid) cout << "Q3 ";
if (i >= mid && j >= mid) cout << "Q4 ";
```

✅ **Use distance for quick patterns**
```cpp
int d = min({i, j, n-1-i, n-1-j});
cout << d % 2;  // Alternating bands
```

✅ **Test with odd n**
- n=5 has clear center
- Easier to verify symmetry
- Then test even n

---

## Problem Summary

| Technique | Application | Complexity |
|-----------|------------|-----------|
| 180° Rotation | Upside-down patterns | ⭐⭐⭐ |
| Quadrants | Different zones | ⭐⭐⭐ |
| Distance | Concentric shapes | ⭐⭐⭐ |
| Bands | Diagonal lines | ⭐⭐ |
| Double Reflect | Both axes mirror | ⭐⭐⭐⭐ |

---

## What You Should Know

After Day 16, you should:
- ✅ Understand rotational symmetry
- ✅ Divide into quadrants
- ✅ Use distance functions
- ✅ Create complex symmetric patterns

---

## Interview Tip

Show understanding of:
- **Symmetry types** (rotation, reflection, both)
- **Coordinate systems** (which axis, which direction)
- **Edge cases** (center, corners, odd/even)

Example: "This pattern has 4-fold rotational symmetry"

---

## Next Steps

Day 17: Loop Optimization
- Refactor for performance
- Function-based approach
- Reusable code patterns
