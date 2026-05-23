# 📝 Day 38: Rotation & Cyclic Arrays - Notes

## Key Patterns

### Pattern 1: Rotate Array by k
```cpp
void rotate(vector<int>& nums, int k) {
    k = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}
// Time: O(n), Space: O(1)
```

---

### Pattern 2: Cyclic Index Management
```cpp
// Circular access without modulo every time
class CircularArray {
    vector<int> arr;
    int size;
    
public:
    int get(int index) {
        return arr[(index % size + size) % size];
    }
};

// Or for simple cases
for (int i = 0; i < n; i++) {
    int next = (i + 1) % n;  // Cyclic next
}
```

---

### Pattern 3: Floyd's Cycle Detection
```cpp
// Detect cycle in circular array
bool hasCycle(vector<int>& nums) {
    for (int start = 0; start < nums.size(); start++) {
        if (nums[start] == 0) continue;
        
        int slow = start, fast = start;
        
        do {
            slow = (slow + nums[slow]) % nums.size();
            fast = (fast + nums[fast]) % nums.size();
            fast = (fast + nums[fast]) % nums.size();
            
            if (slow < 0 || fast < 0) break;
        } while (slow != fast);
        
        if (slow == fast && slow >= 0) return true;
    }
    
    return false;
}
```

---

## Complexity Analysis

| Operation | Time | Space | Notes |
|-----------|------|-------|-------|
| Rotate | O(n) | O(1) | Reversal trick |
| Access | O(1) | O(1) | With modulo |
| Cycle detect | O(n) | O(1) | Floyd's method |

---

## Common Mistakes

1. **Modulo Overflow:** Handle negative indices
2. **Off-by-one:** In rotation boundaries
3. **Cycle Timing:** Slow/fast pointer relationships
4. **Direction:** Clockwise vs counter-clockwise

---

## Interview Tips

✅ **Rotation Insight:** Why does reversal work?  
✅ **Modulo Arithmetic:** Negative handling crucial  
✅ **Floyd Detection:** Different from linked list  
✅ **Follow-up:** How about negative jumps?  

---

## When to Use

- Array rotation operations
- Circular buffer implementation
- Cyclic traversal problems
- Cycle detection in circular context

---

## Advanced Topics

- **Multiple rotations:** Combine operations
- **Reverse rotation:** Counter-clockwise
- **Circular doubly-linked:** More complex cycle
- **Ring buffer:** Practical application
