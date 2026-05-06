# 📝 Day 13 Notes: Key Learnings & Gotchas

## Quick Summary

Today you learned:
- ✅ How to think in 2D coordinates (i,j) instead of just rows
- ✅ Using conditions on coordinates to create shapes
- ✅ The key formulas: i==j for main diagonal, i+j==n-1 for anti-diagonal
- ✅ How to use OR and AND operators for complex shapes
- ✅ Creating boundary, cross, plus, and corner patterns

---

## Problem 1: Grid Pattern (Star Grid)

### Key Points
- **Algorithm:** Fill entire n×n grid with stars
- **Condition:** Always true (print star at every position)
- **Time:** O(n²)

### Step-by-Step Example (n=4)
```
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        // Every position in grid
        cout << "* ";
    }
    cout << "\n";
}

Output:
* * * *
* * * *
* * * *
* * * *
```

### Common Mistakes
```cpp
// ❌ WRONG: Using star pattern instead of grid
for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {  // Triangle shape!
        cout << "* ";
    }
    cout << "\n";
}

// ✓ CORRECT: Both loops iterate n times
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {  // Square grid!
        cout << "* ";
    }
    cout << "\n";
}
```

### Interview Tip
"Grid thinking means both loops iterate the full range. This creates an n×n square, not a triangle."

---

## Problem 2: Cross/X Pattern

### Key Points
- **Algorithm:** Print stars on both diagonals
- **Main diagonal:** i == j
- **Anti-diagonal:** i + j == n - 1
- **Condition:** if (i == j || i + j == n - 1)
- **Time:** O(n²)

### Step-by-Step Example (n=5)
```
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        if (i == j || i + j == n - 1) {
            cout << "* ";
        } else {
            cout << "  ";
        }
    }
    cout << "\n";
}

Output:
*       *
  *   *
    *
  *   *
*       *
```

### Diagonal Explanation
```
Main diagonal (i == j):
(0,0), (1,1), (2,2), (3,3), (4,4)

Anti-diagonal (i + j == n - 1):
(0,4), (1,3), (2,2), (3,1), (4,0)

They intersect at center: (2,2)
```

### Common Mistakes
```cpp
// ❌ WRONG: Only one diagonal
if (i == j) {
    cout << "* ";
}

// ❌ WRONG: Using AND instead of OR
if (i == j && i + j == n - 1) {  // Only center!
    cout << "* ";
}

// ✓ CORRECT: Both diagonals with OR
if (i == j || i + j == n - 1) {
    cout << "* ";
}
```

### Interview Tip
"The key insight is using OR to combine conditions. Each diagonal alone is a line; together they form an X."

---

## Problem 3: Boundary/Frame Pattern

### Key Points
- **Algorithm:** Print stars only on edges
- **Condition:** if (i == 0 || i == n-1 || j == 0 || j == n-1)
- **Time:** O(n²)

### Step-by-Step Example (n=5)
```
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        if (i == 0 || i == n-1 || j == 0 || j == n-1) {
            cout << "* ";
        } else {
            cout << "  ";
        }
    }
    cout << "\n";
}

Output:
* * * * *
*       *
*       *
*       *
* * * * *
```

### Edge Detection
```
i == 0:     First row (top edge)
i == n-1:   Last row (bottom edge)
j == 0:     First column (left edge)
j == n-1:   Last column (right edge)

OR all four = hollow square
```

### Common Mistakes
```cpp
// ❌ WRONG: Using AND (only corners)
if ((i == 0 || i == n-1) && (j == 0 || j == n-1)) {
    cout << "* ";  // Only 4 corners!
}

// ✓ CORRECT: Use OR for all edges
if (i == 0 || i == n-1 || j == 0 || j == n-1) {
    cout << "* ";  // All edges!
}
```

### Interview Tip
"Boundary patterns use OR. AND would give you only corners. OR gives you the entire border frame."

---

## Problem 4: Plus/Cross Pattern

### Key Points
- **Algorithm:** Print stars at center row and center column
- **Find center:** mid = n / 2
- **Condition:** if (i == mid || j == mid)
- **Time:** O(n²)

### Step-by-Step Example (n=5)
```
mid = 5 / 2 = 2

for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        if (i == mid || j == mid) {  // Center row or column
            cout << "* ";
        } else {
            cout << "  ";
        }
    }
    cout << "\n";
}

Output:
    *
    *
* * * * *
    *
    *
```

### Common Mistakes
```cpp
// ❌ WRONG: Using AND (only center point)
int mid = n / 2;
if (i == mid && j == mid) {
    cout << "* ";  // Only one star!
}

// ✓ CORRECT: Use OR for full plus
int mid = n / 2;
if (i == mid || j == mid) {
    cout << "* ";  // Full plus!
}
```

### Interview Tip
"Plus patterns use the center coordinate. i==mid gives the horizontal line, j==mid gives the vertical line."

---

## Problem 5: Corners Pattern

### Key Points
- **Algorithm:** Print stars only at four corners
- **Condition:** if ((i == 0 || i == n-1) && (j == 0 || j == n-1))
- **Note:** Uses AND (not OR like boundary)
- **Time:** O(n²)

### Step-by-Step Example (n=5)
```
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        if ((i == 0 || i == n-1) && (j == 0 || j == n-1)) {
            cout << "* ";
        } else {
            cout << "  ";
        }
    }
    cout << "\n";
}

Output:
*       *
         
         
         
*       *
```

### Corner Detection
```
(0,0)       (0,n-1)
  
  
  
(n-1,0)   (n-1,n-1)

Condition: (i at edge) AND (j at edge)
```

### Common Mistakes
```cpp
// ❌ WRONG: Using OR (gives full border)
if (i == 0 || i == n-1 || j == 0 || j == n-1) {
    cout << "* ";  // Too many stars!
}

// ✓ CORRECT: AND ensures BOTH i and j are edges
if ((i == 0 || i == n-1) && (j == 0 || j == n-1)) {
    cout << "* ";  // Only 4 corners!
}
```

### Interview Tip
"Corners use AND because you need BOTH conditions true. Boundary uses OR because any ONE edge condition is enough."

---

## Why It Matters

**Grid-based thinking** is fundamental:
- **Matrices:** Linear algebra algorithms work on 2D grids
- **Game Grids:** Chess, tic-tac-toe, pathfinding use i,j coordinates
- **Image Processing:** Every pixel has (x,y) coordinates
- **Spreadsheets:** Every cell has (row, col)

Understanding (i,j) coordinates helps you solve **ANY 2D problem**.

---

## Common Mistakes Summary

❌ **Using triangle loop in grid**
→ Only fills upper triangle

❌ **Mixing up OR and AND**
→ Corners pattern becomes boundary
→ Boundary pattern becomes corners

❌ **Forgetting one diagonal**
→ X pattern becomes a single line

❌ **Wrong condition operators**
→ i=0||i=n-1||j=0||j=n-1 (boundary) ≠ (i==0||i==n-1)&&(j==0||j==n-1) (corners)

❌ **Not understanding mid = n/2**
→ Plus pattern doesn't align correctly

---

## Tips and Tricks

✅ **Identify the condition**
- What positions should have stars?
- Write that as a condition

✅ **Test OR vs AND**
- OR: "if ANY condition is true"
- AND: "if ALL conditions are true"

✅ **Trace for n=5**
- Diagonals at (0,0), (1,1), (2,2), (3,3), (4,4)
- Anti-diagonal at (0,4), (1,3), (2,2), (3,1), (4,0)
- Center at (2,2)

✅ **Use grid overlay**
```
  0 1 2 3 4
0 * . . . *
1 . * . * .
2 . . * . .
3 . * . * .
4 * . . . *
```

---

## Condition Reference

| Pattern | Condition | Result |
|---------|-----------|--------|
| Grid | true | All stars |
| Cross | i==j \|\| i+j==n-1 | X pattern |
| Boundary | i==0 \|\| i==n-1 \|\| j==0 \|\| j==n-1 | Frame |
| Plus | i==mid \|\| j==mid | Plus sign |
| Corners | (i==0\|\|i==n-1) && (j==0\|\|j==n-1) | 4 corners |

---

## What You Should Know

After Day 13, you should be able to:
- ✅ Think in 2D grid coordinates (i,j)
- ✅ Use conditions to create shapes
- ✅ Distinguish OR vs AND operators
- ✅ Calculate diagonals: i==j and i+j==n-1
- ✅ Create any boundary-based pattern
- ✅ Verify patterns by hand

---

## Interview Tips

- Clearly explain your condition
- Show why OR vs AND matters
- Draw the grid to verify
- Trace through center positions
- Ask: "What other shapes?"

---

## Next Steps

Day 14 applies these skills:
- **Symmetry patterns** - Mirror shapes
- **Reflection** - Create symmetric designs
- **Point symmetry** - 180-degree rotation

// Checkerboard
if ((i + j) % 2 == 0)
```

---

## Common Mistakes

❌ **Forgetting parentheses in AND conditions**
```cpp
// WRONG:
if (i == 0 || i == n-1 && j == 0 || j == n-1)

// CORRECT:
if ((i == 0 || i == n-1) && (j == 0 || j == n-1))
```
- Operator precedence matters!

❌ **Off-by-one in anti-diagonal**
- `i + j == n - 1`, not i + j == n
- Test: n=4, last cell is (3,0) → 3+0=3=4-1 ✓

❌ **Wrong spacing**
- Print space if condition false: `cout << "  "`
- Or just spaces in else: `cout << " "`

❌ **Condition error**
- `i == j` for diagonal, not i == j - 1
- `i + j == n - 1` for anti, not i + j == n - 2

---

## Tips and Tricks

✅ **Test each condition separately**
```cpp
// Test just main diagonal
if (i == j) cout << "*";

// Test anti-diagonal
if (i + j == n - 1) cout << "*";

// Then combine
if (i == j || i + j == n - 1) cout << "*";
```

✅ **Draw the expected output first**
```
* . . *
. * * .
. * * .
* . . *
```
Then map to conditions

✅ **Use grid coordinates**
```
(0,0) (0,1) (0,2) (0,3)
(1,0) (1,1) (1,2) (1,3)
(2,0) (2,1) (2,2) (2,3)
(3,0) (3,1) (3,2) (3,3)
```
Easier to understand conditions

✅ **Test with n=4 or n=5**
- Easy to trace
- Small enough to verify
- Odd n helps for middle calculations

---

## Problem Summary

| Pattern | Condition | Output |
|---------|-----------|--------|
| Grid | always true | full grid |
| Cross | i==j \|\| i+j==n-1 | X |
| Boundary | edges | hollow square |
| Plus | mid row/col | + |
| Corners | edges AND | four corners |

---

## What You Should Know

After Day 13, you should:
- ✅ Think in grid coordinates
- ✅ Create conditions for positions
- ✅ Combine multiple conditions
- ✅ Debug logical errors

---

## Interview Tip

When asked for grid pattern:
1. Define the grid (n × n)
2. State the condition
3. Show it works (one example)
4. Code confidently

Example: "The X pattern prints star where i==j or i+j==n-1"

---

## Next Steps

Day 14: Symmetry Patterns
- Extends grid thinking
- Introduces mirroring
- Uses these conditions with reflections
