# 🔀 DAY 9: Nested Loops Mastery

**Master multiple nested loops and complex loop control.**

---

## 🎯 Goal of Day 9

By the end of today, you will:

✅ Control 3+ nested loops confidently  
✅ Understand loop variable relationships  
✅ Solve problems with multiple independent dimensions  
✅ Debug complex nested loop logic  

---

## 1️⃣ Multiple Nested Loops

### Pattern with 3 nested loops
```
Size 3:
*
**
***

Then same inverted:
***
**
*
```

### Why 3 loops?
- Outer loop: which section (increasing or decreasing)
- Middle loop: which row within that section
- Inner loop: how many stars per row

---

## 2️⃣ Loop Variable Independence

Key insight: loop variables can be **independent or dependent**.

### Independent loops
```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        // i and j are independent
    }
}
```

### Dependent loops
```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {  // j depends on i
        // j won't run if i == 0
    }
}
```

---

## 3️⃣ Practice Problems

1. Number sequence grid
2. Multiple sections pattern
3. Staircase pattern
4. Combined increasing-decreasing
5. Complex multi-section patterns

---

## Next Steps

Complete all 5 problems and understand when loops depend on each other.

> The more nested loops you master, the more complex patterns you unlock.
