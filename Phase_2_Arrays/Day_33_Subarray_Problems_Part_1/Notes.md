# 📝 Day 33: Subarray Problems (Part 1) - Notes

## Key Patterns

### Pattern 1: Kadane's Algorithm (Max Subarray)
```cpp
int maxSubarray(vector<int>& nums) {
    int maxCurrent = nums[0];
    int maxGlobal = nums[0];
    
    for (int i = 1; i < nums.size(); i++) {
        // Either extend current subarray or start new
        maxCurrent = max(nums[i], maxCurrent + nums[i]);
        maxGlobal = max(maxGlobal, maxCurrent);
    }
    
    return maxGlobal;
}
// Time: O(n), Space: O(1)
```

---

### Pattern 2: Min Subarray (Variation)
```cpp
int minSubarray(vector<int>& nums) {
    int minCurrent = nums[0];
    int minGlobal = nums[0];
    
    for (int i = 1; i < nums.size(); i++) {
        minCurrent = min(nums[i], minCurrent + nums[i]);
        minGlobal = min(minGlobal, minCurrent);
    }
    
    return minGlobal;
}
```

---

### Pattern 3: Circular Array (Max)
```cpp
int maxCircularSubarray(vector<int>& nums) {
    int totalSum = 0;
    int maxKadane = INT_MIN;
    int minKadane = INT_MAX;
    
    for (int num : nums) {
        totalSum += num;
        maxKadane = max(maxKadane, /* kadane logic */);
        minKadane = min(minKadane, /* kadane logic */);
    }
    
    // Case 1: Max subarray is in middle (not circular)
    // Case 2: Max is circular (total - minKadane)
    return max(maxKadane, totalSum - minKadane);
}
```

---

## Complexity Analysis

| Problem | Time | Space | Approach |
|---------|------|-------|----------|
| Max Subarray | O(n) | O(1) | Kadane |
| Min Subarray | O(n) | O(1) | Kadane variant |
| Circular Max | O(n) | O(1) | Two cases |
| With Constraint | O(n) | O(1) | Greedy |

---

## Key Insights

1. **Local vs Global:** Track current and best-so-far
2. **Negative Numbers:** Subarray can be all negative
3. **Circular:** Two cases: middle or wrapping
4. **Prefix Sum:** Alternative for subarray sum = k

---

## Common Mistakes

1. **Empty Subarray:** Must include at least one element
2. **Overflow:** Use long long for sums
3. **Circular Edge:** Don't return total sum if all negative
4. **Initialization:** Handle single element case

---

## Interview Tips

✅ **Kadane's Proof:** Understand why it works  
✅ **Variations:** How to handle constraints?  
✅ **Optimization:** Why not brute force?  
✅ **Follow-up:** Contiguous vs all subarrays?  

---

## When to Use

- Maximum sum subarray
- Minimum sum subarray
- Circular array variations
- Constrained subarray problems

---

## Extension Patterns

- **With exactly k elements:** Sliding window
- **Sum >= target:** Two pointer + prefix
- **Circular with constraint:** Combine approaches
- **Negative handling:** Absolute value tricks
