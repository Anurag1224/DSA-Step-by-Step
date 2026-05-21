# 📝 Day 32: Array Transformation - Notes

## Key Patterns

### Pattern 1: Array Rotation by k
```cpp
// Reversal trick: reverse(A) + reverse(B) = rotate by k
void rotate(vector<int>& nums, int k) {
    k = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}
// Time: O(n), Space: O(1)
```

---

### Pattern 2: Next Permutation
```cpp
void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    
    // Step 1: Find rightmost position where nums[i] < nums[i+1]
    int i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) i--;
    
    if (i >= 0) {
        // Step 2: Find rightmost position > nums[i]
        int j = n - 1;
        while (j > i && nums[j] <= nums[i]) j--;
        
        // Step 3: Swap
        swap(nums[i], nums[j]);
    }
    
    // Step 4: Reverse from i+1 to end
    reverse(nums.begin() + i + 1, nums.end());
}
```

---

### Pattern 3: Rearrange by Conditions
```cpp
// Example: Rearrange positive and negative
void rearrange(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    
    while (left < right) {
        // Move to first negative from left
        while (left < right && arr[left] >= 0) left++;
        // Move to first positive from right
        while (left < right && arr[right] < 0) right--;
        
        if (left < right) {
            swap(arr[left], arr[right]);
        }
    }
}
```

---

## Complexity Analysis

| Operation | Time | Space | Technique |
|-----------|------|-------|-----------|
| Rotate | O(n) | O(1) | Reversal |
| Next Perm | O(n) | O(1) | Two pass |
| Rearrange | O(n) | O(1) | Two pointer |

---

## Common Mistakes

1. **Rotation Offset:** k % n before using
2. **Next Perm:** Conditions must be exact
3. **Boundary:** Off-by-one in pointer movements
4. **Reversal Order:** Correct segment reversal

---

## Interview Tips

✅ **Reversal Trick:** Elegant and efficient  
✅ **Next Permutation:** Classic interview problem  
✅ **Intuition:** Why does rotation work?  
✅ **Variants:** Previous permutation? K rotations?  

---

## When to Use

- Array rotation/shifting
- Permutation generation
- Rearranging with constraints
- Optimization of element positions

---

## Mathematical Insights

**Rotation formula:** rotate(A+B, k) = reverse(A)+reverse(B)
This is a clever observation about cyclic shifts!

**Next Perm:** Works because of lexicographic ordering property
