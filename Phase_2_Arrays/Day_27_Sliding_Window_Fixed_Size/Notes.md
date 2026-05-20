# 📝 Day 27: Sliding Window (Fixed Size) - Notes

## Key Patterns

### Pattern 1: Simple Sliding Window
```cpp
int left = 0;
for (int right = 0; right < n; right++) {
    // Add arr[right] to window
    
    if (right - left + 1 > k) {
        // Remove arr[left] from window
        left++;
    }
    
    // Process [left, right]
}
```
**Window size:** Always k elements

---

### Pattern 2: Deque for Min/Max
```cpp
deque<int> dq;  // Stores indices

for (int i = 0; i < n; i++) {
    // Remove indices outside window
    if (!dq.empty() && dq.front() < i - k + 1) {
        dq.pop_front();
    }
    
    // Remove smaller elements (for max)
    while (!dq.empty() && arr[dq.back()] < arr[i]) {
        dq.pop_back();
    }
    
    dq.push_back(i);
    
    if (i >= k - 1) {
        // Process max at dq.front()
    }
}
```

---

### Pattern 3: Running Calculation
```cpp
// Maintain sum/product/count in current window
int sum = 0;
for (int i = 0; i < k; i++) sum += arr[i];

for (int i = k; i < n; i++) {
    sum += arr[i] - arr[i - k];
    // Process sum
}
```

---

## Complexity Analysis

| Operation | Time | Space |
|-----------|------|-------|
| Build window | O(n) | O(k) |
| Query (simple) | O(1) | O(1) |
| Min/Max (deque) | O(n) | O(k) |
| Update element | O(1) | O(1) |

---

## Common Mistakes

1. **Window Size:** Off-by-one in window boundary
2. **Deque Invariant:** Not maintaining decreasing order
3. **Index Tracking:** Confusing element value with index
4. **Overflow:** Integer overflow in sum calculations

---

## Interview Tips

✅ **Simpler Pattern:** Fixed size is easier than variable  
✅ **Deque Knowledge:** Critical for min/max problems  
✅ **Space Optimization:** Can use arrays for small k  
✅ **Follow-up:** What if k varies? (Variable window)  

---

## When to Use

- Fixed window size required
- Need min/max in every window
- Running calculation like average
- Stream processing (online algorithm)

---

## Deque Optimization Notes

- Maintains max/min in O(n) total time
- Each element enters deque once, leaves once
- Space is O(k), not O(n)
- Better than segment tree for simple max/min
