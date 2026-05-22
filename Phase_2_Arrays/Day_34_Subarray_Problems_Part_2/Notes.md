# 📝 Day 34: Subarray Problems (Part 2) - Notes

## Key Patterns

### Pattern 1: Max Product Subarray
```cpp
int maxProduct(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    int maxProd = nums[0];
    int minProd = nums[0];
    int result = nums[0];
    
    for (int i = 1; i < nums.size(); i++) {
        // Negative flips max to min
        if (nums[i] < 0) {
            swap(maxProd, minProd);
        }
        
        maxProd = max(nums[i], maxProd * nums[i]);
        minProd = min(nums[i], minProd * nums[i]);
        result = max(result, maxProd);
    }
    
    return result;
}
```

---

### Pattern 2: Longest Ones with Flips
```cpp
// At most k flips (sliding window variant)
int longestOnes(vector<int>& nums, int k) {
    int left = 0, zeroCount = 0;
    int maxLen = 0;
    
    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] == 0) zeroCount++;
        
        while (zeroCount > k) {
            if (nums[left] == 0) zeroCount--;
            left++;
        }
        
        maxLen = max(maxLen, right - left + 1);
    }
    
    return maxLen;
}
```

---

### Pattern 3: XOR Subarray Queries
```cpp
// Find max XOR of subarray
int maxXorSubarray(vector<int>& nums) {
    int maxXor = 0;
    int currentXor = 0;
    
    for (int num : nums) {
        currentXor = max(num, currentXor ^ num);
        maxXor = max(maxXor, currentXor);
    }
    
    return maxXor;
}
```

---

## Complexity Analysis

| Problem | Time | Space | Key Technique |
|---------|------|-------|--------------|
| Max Product | O(n) | O(1) | Track min+max |
| Longest Ones | O(n) | O(1) | Sliding window |
| Max XOR | O(n) | O(1) | XOR properties |

---

## Common Mistakes

1. **Min Tracking:** Max product needs min too
2. **Negative Sign:** Multiplying by negative flips
3. **Zero Handling:** Product becomes zero
4. **XOR Properties:** a ⊕ a = 0

---

## Interview Tips

✅ **Why Min+Max:** Negative can flip signs  
✅ **XOR Insight:** Self-cancellation property  
✅ **Constraint Types:** K flips, at most k...  
✅ **Follow-up:** What about circular?  

---

## When to Use

- Maximum product subarray
- Longest subarray with constraint
- XOR-based subarray problems
- Bit manipulation combined with arrays

---

## Advanced Extensions

- **Product with negative limit:** Different DP
- **Multiple subarrays:** Divide and conquer
- **Even-length subarrays:** Extra constraint
- **Palindrome subarrays:** Different pattern
