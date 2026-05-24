# 📝 Day 43: Array with Constraints - Notes

## Key Patterns

### Pattern 1: First Missing Positive
```cpp
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    
    // Place each number in its position
    for (int i = 0; i < n; i++) {
        while (nums[i] > 0 && nums[i] <= n && 
               nums[nums[i] - 1] != nums[i]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    
    // Find first position not matching
    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    
    return n + 1;
}
// Time: O(n), Space: O(1)
```

---

### Pattern 2: Contains Duplicate with Constraint
```cpp
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    
    for (int num : nums) {
        if (seen.count(num)) {
            return true;
        }
        seen.insert(num);
    }
    
    return false;
}

// With distance constraint [i - j <= k]
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> window;
    
    for (int i = 0; i < nums.size(); i++) {
        if (window.count(nums[i])) {
            return true;
        }
        
        window.insert(nums[i]);
        
        if (window.size() > k) {
            window.erase(nums[i - k]);
        }
    }
    
    return false;
}
```

---

### Pattern 3: Binary Array Sorting
```cpp
void sortBinaryArray(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    
    while (left < right) {
        while (left < right && nums[left] == 0) left++;
        while (left < right && nums[right] == 1) right--;
        
        if (left < right) {
            swap(nums[left], nums[right]);
        }
    }
}
// Time: O(n), Space: O(1)
```

---

## Complexity Analysis

| Problem | Time | Space | Constraint |
|---------|------|-------|-----------|
| First Missing | O(n) | O(1) | [1, n+1] |
| Contains Dup | O(n) | O(n) | Value unique |
| With Distance | O(n) | O(k) | Distance k |
| Binary Sort | O(n) | O(1) | Only 0,1 |

---

## Key Insights

1. **Constraint Exploitation:** Use range for optimization
2. **Index Placement:** Put elements in target positions
3. **Window Technique:** Sliding for distance constraints
4. **Partition:** Two pointer for binary

---

## Common Mistakes

1. **Index Out of Bounds:** Check before accessing
2. **Cycle in Swaps:** Avoid infinite loops
3. **Off-by-one:** In missing number calculation
4. **Window Size:** <= vs < comparison

---

## Interview Tips

✅ **Constraint Analysis:** How can constraint help?  
✅ **Space Optimization:** Use array as hash  
✅ **Index Placement:** Clever in-place solution  
✅ **Follow-up:** What if constraint is different?  

---

## When to Use

- Arrays with elements in specific range
- Finding missing numbers efficiently
- Binary arrays (0/1 only)
- Distance-constrained problems

---

## Advanced Concepts

- **Bucket sort:** For small range
- **Counting sort:** For known range
- **Pigeonhole principle:** Guarantee existence
- **Index as hash:** O(1) space with array
