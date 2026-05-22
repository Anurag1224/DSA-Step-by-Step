# 📝 Day 35: Subsequence vs Subarray - Notes

## Key Differences

### Subarray: Contiguous Elements
```cpp
// [1, 2, 3] -> Subarrays: [1], [2], [3], [1,2], [2,3], [1,2,3]
```

### Subsequence: Order Preserved, Not Contiguous
```cpp
// [1, 2, 3] -> Subsequences: [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3], []
```

---

## Pattern 1: Longest Increasing Subsequence (DP)
```cpp
// O(n log n) solution with binary search
int lengthOfLIS(vector<int>& nums) {
    vector<int> tails;
    
    for (int num : nums) {
        // Find position to replace
        auto it = lower_bound(tails.begin(), tails.end(), num);
        
        if (it == tails.end()) {
            tails.push_back(num);
        } else {
            *it = num;  // Replace with smaller value
        }
    }
    
    return tails.size();
}
```

---

## Pattern 2: Longest Increasing Subarray (One Pass)
```cpp
int longestIncreasingSubarray(vector<int>& nums) {
    int maxLen = 1, currentLen = 1;
    
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[i - 1]) {
            currentLen++;
        } else {
            currentLen = 1;
        }
        maxLen = max(maxLen, currentLen);
    }
    
    return maxLen;
}
// Time: O(n), Space: O(1)
```

---

## Pattern 3: Longest Common Subsequence (2D DP)
```cpp
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    return dp[m][n];
}
```

---

## Complexity Comparison

| Problem | Subarray Time | Subsequence Time | Approach |
|---------|--------------|------------------|----------|
| Longest Inc | O(n) | O(n log n) | Greedy vs DP |
| Common | O(n) | O(m*n) | Direct vs DP |
| Sum = k | O(n) | O(2^n) | Prefix vs DFS |

---

## Key Insights

1. **Contiguity Matters:** Subarray ≈ easy, Subsequence ≈ hard
2. **DP for Subsequence:** Often needs 2D or memoization
3. **Greedy for Subarray:** Often works due to contiguity
4. **Longest Inc:** Binary search trick makes it O(n log n)

---

## Common Mistakes

1. **Confusing Terms:** What exactly is the problem asking?
2. **Complexity Jump:** Subsequence problems harder
3. **DP State:** Forgetting what state represents
4. **Space Optimization:** Can 2D DP become 1D?

---

## Interview Tips

✅ **Clarify Requirements:** Contiguous or not?  
✅ **Discuss Complexity:** Why the time difference?  
✅ **LIS Insight:** Binary search trick is clever  
✅ **Space:** Can we optimize the DP table?  

---

## When to Use

- **Subarray:** When elements must be adjacent
- **Subsequence:** When order matters but not adjacency
- **Substring:** Special subarray for strings
- **Subsequence:** More flexible, but harder

---

## Real Problem Examples

**Subarray:**
- Maximum sum subarray (Kadane)
- Subarray with sum = k (prefix sum)
- Longest subarray with property

**Subsequence:**
- Longest increasing subsequence (DP/Binary search)
- Longest common subsequence (Edit distance)
- Number of distinct subsequences
