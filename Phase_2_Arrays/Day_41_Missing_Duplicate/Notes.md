# 📝 Day 41: Missing & Duplicate - Notes

## Key Patterns

### Pattern 1: Find Missing Number (XOR)
```cpp
int missingNumber(vector<int>& nums) {
    int xor_all = 0, xor_nums = 0;
    
    // XOR all indices [0, n]
    for (int i = 0; i <= nums.size(); i++) {
        xor_all ^= i;
    }
    
    // XOR all numbers
    for (int num : nums) {
        xor_nums ^= num;
    }
    
    // xor_all ^ xor_nums cancels duplicates
    return xor_all ^ xor_nums;
}
// Time: O(n), Space: O(1)
```

---

### Pattern 2: Find Duplicate (Marking)
```cpp
// Arrays with elements in [1, n]
int findDuplicate(vector<int>& nums) {
    int slow = 0, fast = 0;
    
    // Floyd's cycle detection
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    
    // Find cycle entrance
    slow = 0;
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    
    return slow;
}
// Time: O(n), Space: O(1)
```

---

### Pattern 3: Find All Missing (Marking)
```cpp
vector<int> findAllMissing(vector<int>& nums) {
    vector<int> result;
    
    // Mark indices by making values negative
    for (int num : nums) {
        int idx = abs(num) - 1;
        if (nums[idx] > 0) {
            nums[idx] = -nums[idx];
        }
    }
    
    // Unmarked indices are missing
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            result.push_back(i + 1);
        }
    }
    
    return result;
}
```

---

## Complexity Analysis

| Problem | Time | Space | Technique |
|---------|------|-------|-----------|
| Missing | O(n) | O(1) | XOR |
| Duplicate | O(n) | O(1) | Floyd |
| All Missing | O(n) | O(1) | Marking |

---

## Key Insights

1. **XOR Property:** a ⊕ a = 0, cancels pairs
2. **Marking:** Use indices for O(1) space
3. **Floyd's:** Treats array as linked list
4. **Negative Index:** Clever marking technique

---

## Common Mistakes

1. **XOR Order:** Matters if thinking additively
2. **Index Bounds:** Off-by-one with 1-indexed
3. **Modification:** Marking modifies input
4. **Reset:** Don't forget to restore array

---

## Interview Tips

✅ **XOR Insight:** Why does self-cancellation work?  
✅ **Floyd's Application:** To arrays not just lists  
✅ **Space Claim:** Marking modifies, not "O(1)"  
✅ **Follow-up:** Multiple duplicates? Negatives?  

---

## When to Use

- Finding missing numbers
- Finding duplicate numbers
- Constraint-based arrays [1, n]
- Space-optimized solutions

---

## Advanced Extensions

- **Multiple missing:** Different approach
- **Negatives allowed:** Hash set needed
- **K duplicates:** Multiple passes
- **Weighted:** Different formula for XOR
