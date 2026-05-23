# 📝 Day 39: Searching in Special Arrays - Notes

## Key Patterns

### Pattern 1: Search in Rotated Array
```cpp
int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) return mid;
        
        // Determine which half is sorted
        if (nums[mid] >= nums[left]) {
            // Left half is sorted
            if (target >= nums[left] && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            // Right half is sorted
            if (target > nums[mid] && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    
    return -1;
}
```

---

### Pattern 2: Find Peak Element
```cpp
int findPeak(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] < nums[mid + 1]) {
            // Right has larger element
            left = mid + 1;
        } else {
            // Left or mid is peak
            right = mid;
        }
    }
    
    return left;
}
```

---

### Pattern 3: Search in Bitonic Array
```cpp
// Array increases then decreases
int searchBitonic(vector<int>& nums, int target) {
    // Find peak
    int peak = findPeak(nums);
    
    // Binary search in increasing part
    int left = binarySearch(nums, 0, peak, target, true);
    if (left != -1) return left;
    
    // Binary search in decreasing part
    return binarySearch(nums, peak + 1, nums.size() - 1, target, false);
}
```

---

## Complexity Analysis

| Problem | Time | Space | Key Insight |
|---------|------|-------|------------|
| Rotated | O(log n) | O(1) | Identify sorted half |
| Peak | O(log n) | O(1) | Convergence point |
| Bitonic | O(log n) | O(1) | Find peak, search twice |

---

## Common Mistakes

1. **Equal Elements:** Edge case with duplicates
2. **Comparison Logic:** Which half is sorted?
3. **Peak Definition:** >= vs >
4. **Boundary:** Include/exclude endpoints

---

## Interview Tips

✅ **Rotation Logic:** Careful comparison  
✅ **Peak Insight:** Guaranteed to exist (middle never < both)  
✅ **Binary Search Variants:** Important skill  
✅ **Follow-up:** What with duplicates?  

---

## When to Use

- Finding in rotated sorted array
- Peak finding in array
- Bitonic array search
- Binary search variations

---

## Advanced Scenarios

- **Duplicates:** Becomes tricky, O(n) worst case
- **Multiple peaks:** Find any one or all
- **Nearly sorted:** Similar approach
- **K-times rotated:** Same pattern, adjusted
