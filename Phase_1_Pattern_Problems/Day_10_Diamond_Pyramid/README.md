# 💎 DAY 10: Diamond & Pyramid Patterns

**Master symmetry, centering, and complex shapes.**

---

## 🎯 Goal of Day 10

By the end of today, you will:

✅ Understand space calculation for centering  
✅ Print diamond patterns with precision  
✅ Create pyramids with proper alignment  
✅ Think in terms of spaces and characters  

---

## 1️⃣ Diamond Pattern

A diamond requires:
1. Expanding part (increasing spaces and stars)
2. Contracting part (decreasing spaces and stars)

### Example (n=3)
```
  *      (2 spaces, 1 star)
 ***     (1 space, 3 stars)
*****    (0 spaces, 5 stars)
 ***     (1 space, 3 stars)
  *      (2 spaces, 1 star)
```

Pattern observation:
- Row i has (n-i-1) spaces and (2*i+1) stars
- After middle, mirror the top part

---

## 2️⃣ Space Calculation

For centering with width w and element width e:
```
spaces_needed = (w - e) / 2
```

---

## 3️⃣ Practice Problems

1. Diamond pattern
2. Pyramid pattern
3. Inverted pyramid
4. Hollow diamond
5. Complex pyramid

---

## Next Steps

Complete all problems focusing on space calculation.

> Spaces are as important as the visible characters. Count them carefully.
