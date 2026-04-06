# Day 3 Notes: Input Constraints & Edge Cases

## Common Input Constraints

### Array Sizes
- N = 1 to 10^5 (typical range)
- Empty arrays possible?
- Single element arrays

### Numbers
- Range: -10^9 to 10^9
- Zero values
- Negative numbers
- Integer overflow (INT_MAX = 2^31-1)

### Strings
- Length: 1 to 10^5
- Empty strings
- Special characters
- Unicode considerations

## Edge Case Checklist

- [ ] Empty input
- [ ] Single element
- [ ] Maximum size input
- [ ] Minimum size input
- [ ] All same values
- [ ] Negative values
- [ ] Zero values
- [ ] Boundary conditions

## Defensive Programming Patterns

```cpp
// Safe array access
if (arr.empty()) return -1;
if (index < 0 || index >= arr.size()) return -1;

// Safe division
if (denominator == 0) return ERROR_VALUE;

// String validation
if (str.empty() || str.length() > MAX_LEN) return false;
```

## Common Mistakes

- Assuming arrays aren't empty
- Not checking for division by zero
- Using int for large sums (overflow)
- Not handling negative indices
- Assuming strings have minimum length