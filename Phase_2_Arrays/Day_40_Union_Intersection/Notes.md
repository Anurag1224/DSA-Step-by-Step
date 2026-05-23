# 📝 Day 40: Union & Intersection - Notes

## Key Patterns

### Pattern 1: Array Intersection (Sorted)
```cpp
// Two pointer approach
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    int i = 0, j = 0;
    
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] == nums2[j]) {
            // Add only if different from last
            if (result.empty() || result.back() != nums1[i]) {
                result.push_back(nums1[i]);
            }
            i++; j++;
        } else if (nums1[i] < nums2[j]) {
            i++;
        } else {
            j++;
        }
    }
    
    return result;
}
// Time: O(n+m), Space: O(1) excluding result
```

---

### Pattern 2: Array Union (Sorted)
```cpp
vector<int> unionSets(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    int i = 0, j = 0;
    
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] == nums2[j]) {
            result.push_back(nums1[i]);
            i++; j++;
        } else if (nums1[i] < nums2[j]) {
            result.push_back(nums1[i++]);
        } else {
            result.push_back(nums2[j++]);
        }
    }
    
    // Add remaining
    while (i < nums1.size()) result.push_back(nums1[i++]);
    while (j < nums2.size()) result.push_back(nums2[j++]);
    
    return result;
}
// Time: O(n+m), Space: O(result size)
```

---

### Pattern 3: Hash Set Approach
```cpp
// For unsorted or k arrays
vector<int> intersection(vector<vector<int>>& arrays) {
    unordered_set<int> common(arrays[0].begin(), arrays[0].end());
    
    for (int i = 1; i < arrays.size(); i++) {
        unordered_set<int> current(arrays[i].begin(), arrays[i].end());
        unordered_set<int> temp;
        
        for (int num : common) {
            if (current.count(num)) {
                temp.insert(num);
            }
        }
        
        common = temp;
    }
    
    return vector<int>(common.begin(), common.end());
}
```

---

## Complexity Analysis

| Approach | Time | Space | Best For |
|----------|------|-------|----------|
| Two pointer | O(n+m) | O(1) | Sorted arrays |
| Hash set | O(n+m) | O(n) | Unsorted arrays |
| K arrays | O(n*k) | O(n) | Multiple arrays |

---

## Common Mistakes

1. **Duplicates:** Handle properly (one-time only)
2. **Sorted Order:** Result must be sorted too
3. **Empty Arrays:** Edge case handling
4. **Space Claim:** Hash set requires O(n)

---

## Interview Tips

✅ **Sorted Advantage:** Two pointer optimal  
✅ **Duplicate Handling:** Skip or keep?  
✅ **K Arrays:** Intersection shrinks set  
✅ **Follow-up:** What if k arrays? Weights?  

---

## When to Use

- Finding common elements (intersection)
- Combining unique elements (union)
- Set operations on arrays
- K-way merge problems

---

## Real Applications

- **Database joins:** INNER JOIN, OUTER JOIN
- **API result merging:** Common valid ids
- **Permissions:** Users with all permissions
- **Inventory:** Items in all warehouses
