# 📝 Day 42: Arrangement Problems - Notes

## Key Patterns

### Pattern 1: Rearrange Positive/Negative
```cpp
void rearrangePositiveNegative(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    
    while (left < right) {
        // Find first negative
        while (left < right && arr[left] >= 0) left++;
        // Find first positive
        while (left < right && arr[right] < 0) right--;
        
        if (left < right) {
            swap(arr[left], arr[right]);
        }
    }
}
// Time: O(n), Space: O(1)
```

---

### Pattern 2: Queue Reconstruction by Height
```cpp
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    // Sort by height descending, then by k ascending
    sort(people.begin(), people.end(), [](auto& a, auto& b) {
        return a[0] != b[0] ? a[0] > b[0] : a[1] < b[1];
    });
    
    vector<vector<int>> result;
    for (auto& p : people) {
        result.insert(result.begin() + p[1], p);
    }
    
    return result;
}
// Time: O(n^2), Space: O(n)
```

---

### Pattern 3: Wiggle Sort
```cpp
void wiggleSort(vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
        // At even indices, nums[i] < nums[i+1]
        // At odd indices, nums[i] > nums[i+1]
        if ((i % 2 == 0 && nums[i] > nums[i + 1]) ||
            (i % 2 == 1 && nums[i] < nums[i + 1])) {
            swap(nums[i], nums[i + 1]);
        }
    }
}
// Time: O(n), Space: O(1)
```

---

## Complexity Analysis

| Problem | Time | Space | Approach |
|---------|------|-------|----------|
| Rearrange | O(n) | O(1) | Two pointer |
| Queue | O(n^2) | O(n) | Sorting + insert |
| Wiggle | O(n) | O(1) | Single pass |

---

## Key Insights

1. **Greedy Selection:** Often optimal for arrangement
2. **Sorting Strategy:** Different orders for different goals
3. **Swap Operations:** Minimal modifications
4. **Invariant Maintenance:** Keep constraints valid

---

## Common Mistakes

1. **Comparison Logic:** Correct wiggle pattern
2. **Insert Overhead:** O(n^2) for queue reconstruction
3. **Boundary:** Array bounds in loop
4. **Edge Case:** Empty or single element

---

## Interview Tips

✅ **Greedy Proof:** Why does approach work?  
✅ **Sorting Key:** How to choose sort order?  
✅ **Optimization:** Can we beat O(n^2)?  
✅ **Follow-up:** What if ties in height?  

---

## When to Use

- Rearranging by conditions
- Greedy selection problems
- Constraint satisfaction
- Optimization problems

---

## Real Applications

- **Queue management:** Arrange by attributes
- **Task scheduling:** Greedy selection
- **Array formatting:** Alternating patterns
- **Resource allocation:** Optimal arrangement
