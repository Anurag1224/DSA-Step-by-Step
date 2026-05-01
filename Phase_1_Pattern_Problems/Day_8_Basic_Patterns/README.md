# 📦 DAY 8: Basic Patterns

**Learn the foundation of pattern printing with simple nested loops.**

---

## 🎯 Goal of Day 8

By the end of today, you will:

✅ Understand nested loops in pattern context  
✅ Print squares and rectangles of any size  
✅ Learn row-column thinking  
✅ Build confidence with basic patterns  

---

## 1️⃣ What is a Pattern Problem?

A pattern problem asks you to **print a visual shape** using nested loops.

### Example: Square of size 3
```
***
***
***
```

To print this:
- Outer loop: iterate 3 times for each row
- Inner loop: iterate 3 times to print 3 stars per row
- After each row completes, go to next line

### Analysis
- Rows (outer loop): n iterations
- Columns (inner loop): m iterations per row
- Time Complexity: O(n × m)
- Space Complexity: O(1)

---

## 2️⃣ Basic Patterns (Core Concepts)

### Pattern 1: Square
```
Size 3:
***
***
***

Size 5:
*****
*****
*****
*****
*****
```

Loop structure:
```cpp
for (int i = 0; i < n; i++) {      // rows
    for (int j = 0; j < n; j++) {  // columns
        cout << "*";
    }
    cout << "\n";
}
```

### Pattern 2: Rectangle
```
Rows=3, Cols=5:
*****
*****
*****
```

Loop structure:
```cpp
for (int i = 0; i < rows; i++) {      
    for (int j = 0; j < cols; j++) {  
        cout << "*";
    }
    cout << "\n";
}
```

### Pattern 3: Hollow Square
```
Size 4:
****
*  *
*  *
****
```

Condition:
- First row: print all stars
- Last row: print all stars
- Middle rows: print star, spaces, star

---

## 3️⃣ Think Before Coding

For any pattern:
1. **Identify structure** — which rows are special?
2. **Find the condition** — when to print what?
3. **Dry run** — trace rows and columns manually
4. **Code incrementally** — get one part working first

---

## 4️⃣ Edge Cases

- n = 1: Single star
- n = 2: Smallest valid pattern
- Large n: Make sure output is correct

---

## Practice Problems

1. Square of stars
2. Rectangle of stars
3. Hollow square
4. Right triangle of stars
5. Inverted right triangle

---

## Next Steps

Complete all 5 problems in this directory.

> Nested loops are your superpower. Master them here, and everything else becomes easier.
