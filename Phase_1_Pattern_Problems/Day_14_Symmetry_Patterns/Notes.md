# 📝 DAY 14 Notes: Symmetry Patterns

## Key Concepts

### What is Symmetry?

**Symmetry** = mirror image on one or both axes

- **Horizontal mirror** → left/right reflection
- **Vertical mirror** → top/bottom reflection  
- **Diagonal mirror** → along diagonal line
- **Point symmetry** → 180-degree rotation

### Approach

1. Create one half of the pattern
2. Mirror/reflect it
3. Combine both halves

---

## Symmetry Types

### Horizontal Mirroring

Create left half, then mirror to right:
```cpp
for (int i = 0; i < n; i++) {
    // Left side: increasing
    for (int j = 0; j <= i; j++) {
        cout << "*";
    }
    // Mirror: decreasing (excluding middle)
    for (int j = i - 1; j >= 0; j--) {
        cout << "*";
    }
    cout << "\n";
}
```

Output:
```
*
***
*****
*******
```

**Key**: Second loop goes backward through same indices

### Vertical Mirroring

Create top half, then mirror to bottom:
```cpp
// Top half
for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
        cout << "*";
    }
    cout << "\n";
}

// Bottom half (mirror top, reversed)
for (int i = n - 2; i >= 0; i--) {
    for (int j = 0; j <= i; j++) {
        cout << "*";
    }
    cout << "\n";
}
```

Output:
```
*
**
***
***
**
*
```

**Key**: Second section reverses through rows

### Diagonal Symmetry

Main diagonal:
```cpp
if (i == j)
    cout << "*";
```

Anti-diagonal:
```cpp
if (i + j == n - 1)
    cout << "*";
```

Both diagonals:
```cpp
if (i == j || i + j == n - 1)
    cout << "*";
```

---

## Important Points

### Avoiding Duplication
```cpp
// TOP HALF: i from 0 to n-1
for (int i = 0; i < n; i++) {
    // Code
}

// BOTTOM HALF: i from n-2 to 0
for (int i = n - 2; i >= 0; i--) {  // Start from n-2!
    // Same code
}
```

Start second loop at **n-2** to avoid repeating the middle row.

### Horizontal Mirror Index Inversion
```cpp
// Forward: 0, 1, 2, ..., i
for (int j = 0; j <= i; j++) {
    cout << content[j];
}

// Backward: i-1, i-2, ..., 0
for (int j = i - 1; j >= 0; j--) {
    cout << content[j];
}
```

Second loop goes backward through same range.

---

## Common Mistakes

❌ **Starting second loop at wrong index**
- Horizontal: both loops use same indices
- Vertical: second loop at n-2, not n-1
- Diagonal: different condition entirely

❌ **Forgetting to invert logic**
- Horizontal: need reversed loop
- Vertical: need reversed row loop
- Without inversion: no mirror effect

❌ **Adding extra spaces in mirror**
- Mirror should be identical logic
- Just change loop direction
- Don't add new spaces

❌ **Diagonal off-by-one**
- `i + j == n - 1`, not n
- Test: n=4, corner is (3,0) → 3+0=3=4-1 ✓

---

## Tips and Tricks

✅ **Reuse code for symmetry**
```cpp
// Define as function
void printRow(int i, int n) {
    for (int j = 0; j <= i; j++) {
        cout << "*";
    }
}

// Use twice
for (int i = 0; i < n; i++) printRow(i, n);
for (int i = n-2; i >= 0; i--) printRow(i, n);
```

✅ **Test symmetry mathematically**
- Draw grid with coordinates
- Verify symmetry on paper
- Then code

✅ **Use grid visualization**
```
(0,0) (0,1) (0,2)
(1,0) (1,1) (1,2)
(2,0) (2,1) (2,2)
```
- Mark diagonal: (0,0), (1,1), (2,2)
- Mark anti: (0,2), (1,1), (2,0)

✅ **Start with simple triangle**
- Once triangle works
- Add mirror with confidence

---

## Problem Summary

| Type | Approach | Key |
|------|----------|-----|
| Horizontal | Left + reversed right | Same row, backward loop |
| Vertical | Top + reversed bottom | n-2 starting point |
| Diagonal | Condition i==j | Main diagonal |
| Anti-Diagonal | Condition i+j==n-1 | Other diagonal |
| Both | OR the conditions | X pattern |

---

## What You Should Know

After Day 14, you should:
- ✅ Create horizontally mirrored patterns
- ✅ Create vertically mirrored patterns
- ✅ Use diagonal conditions
- ✅ Combine symmetries

---

## Interview Tip

Pattern with symmetry shows:
- Code reusability
- Mathematical thinking
- Attention to detail

Explain: "I'll create one half, then mirror it to avoid duplication"

---

## Next Steps

Day 15: Complex Patterns
- Combines multiple concepts
- No new core theory
- Applied practice
