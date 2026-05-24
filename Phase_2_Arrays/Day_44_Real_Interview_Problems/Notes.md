# 📝 Day 44: Real Interview Problems - Notes

## Complexity & Techniques Map

### Problem Complexity Tiers

**Tier 1 (Two Techniques):**
- Trapping rain water (two pointer + prefix)
- Gas station (greedy + circular)
- Best time buy/sell III (DP + constraints)

**Tier 2 (Three Techniques):**
- Largest rectangle (histogram + monotonic stack)
- Skyline problem (sorting + heap)
- Candy distribution (two pass greedy)

**Tier 3 (Multiple Optimizations):**
- Maximum sliding window submatrix
- K largest elements (stream processing)
- Median of stream (heap optimization)

---

## Key Patterns

### Pattern 1: Multiple Constraints
```cpp
// Problem: Maximize profit with constraint
// Technique: DP with state tracking
vector<int> dp_buy(n), dp_sell(n);

for (int i = 0; i < n; i++) {
    // Transition logic with constraints
    // Track multiple states in parallel
}
```

### Pattern 2: Stack-Based Optimization
```cpp
// Monotonic stack for histogram
stack<int> st;
vector<int> left_smaller(n), right_smaller(n);

for (int i = 0; i < n; i++) {
    while (!st.empty() && heights[st.top()] >= heights[i]) {
        st.pop();
    }
    left_smaller[i] = st.empty() ? -1 : st.top();
    st.push(i);
}
```

### Pattern 3: Greedy with Validation
```cpp
// Gas station: can start from position i?
bool canStart(vector<int>& gas, vector<int>& cost) {
    int tank = 0;
    for (int i = 0; i < n; i++) {
        tank += gas[i] - cost[i];
        if (tank < 0) return false;
    }
    return true;
}
```

---

## Common Approaches

| Problem Type | Approach | Time |
|-------------|----------|------|
| Maximize profit | DP or greedy | O(n) or O(n log n) |
| Histogram max | Monotonic stack | O(n) |
| Skyline | Sweep line | O(n log n) |
| Reservoir | Online DP | O(n) |

---

## Integration Strategies

1. **Combine Patterns:** Two pointer + prefix sum
2. **Optimize Later:** Brute force → optimize
3. **State Management:** Track multiple values
4. **Transition Logic:** Clear state changes

---

## Interview Tips

✅ **Problem Breakdown:** Identify components  
✅ **Brute Force First:** Then optimize  
✅ **State Clarity:** Define DP states carefully  
✅ **Edge Cases:** Handle constraints properly  

---

## Learning Approach

1. **Understand Base Problem:** Simplify if needed
2. **Add Constraints:** One at a time
3. **Identify Techniques:** What patterns apply?
4. **Combine Optimally:** Balance complexity
5. **Prove Correctness:** Why does it work?

---

## Advanced Concepts Used

- Monotonic stacks (sequence problems)
- Multiple DP states (constrained optimization)
- Greedy with proof (activity selection)
- Binary search (feasibility checking)
- Heap (K-way merging)
