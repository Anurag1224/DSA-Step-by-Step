# 📝 Day 37: Frequency & Counting - Notes

## Key Patterns

### Pattern 1: Top K Frequent Elements
```cpp
// Using heap
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    for (int num : nums) count[num]++;
    
    // Min heap of size k
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    for (auto& p : count) {
        pq.push({p.second, p.first});
        if (pq.size() > k) pq.pop();
    }
    
    vector<int> result;
    while (!pq.empty()) {
        result.push_back(pq.top().second);
        pq.pop();
    }
    return result;
}
// Time: O(n log k), Space: O(n)
```

---

### Pattern 2: Group Anagrams
```cpp
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> map;
    
    for (string& s : strs) {
        string sorted_s = s;
        sort(sorted_s.begin(), sorted_s.end());
        map[sorted_s].push_back(s);
    }
    
    vector<vector<string>> result;
    for (auto& p : map) {
        result.push_back(p.second);
    }
    return result;
}
// Time: O(n * k log k), Space: O(n*k)
```

---

### Pattern 3: Find All Duplicates
```cpp
// In-place marking (array elements in range [1, n])
vector<int> findDuplicates(vector<int>& nums) {
    unordered_set<int> seen;
    vector<int> result;
    
    for (int num : nums) {
        if (seen.count(num)) {
            result.push_back(num);
        }
        seen.insert(num);
    }
    return result;
}

// In-place without extra space: mark with negative index
vector<int> findDuplicatesInPlace(vector<int>& nums) {
    vector<int> result;
    
    for (int num : nums) {
        int idx = abs(num) - 1;
        if (nums[idx] < 0) {
            result.push_back(abs(num));
        } else {
            nums[idx] = -nums[idx];
        }
    }
    return result;
}
```

---

## Complexity Analysis

| Problem | Time | Space | Technique |
|---------|------|-------|-----------|
| Top K | O(n log k) | O(n) | Heap |
| Anagrams | O(n*k log k) | O(n*k) | Hash + sort |
| Duplicates | O(n) | O(k) | Hash or marking |

---

## Common Mistakes

1. **Hash Map Size:** May be larger than k
2. **Sorting Key:** For anagrams, sorted string is key
3. **Marking Index:** off-by-one with 1-indexed arrays
4. **Space Claim:** "O(1)" marking modifies input

---

## Interview Tips

✅ **Heap vs Sorting:** O(n log k) better than O(n log n)  
✅ **Anagram Key:** Sorted string is natural choice  
✅ **Marking:** Integer array optimization trick  
✅ **Follow-up:** What if array has 0? Negatives?  

---

## When to Use

- Top K problems (frequent, expensive, heavy hitters)
- Grouping similar elements
- Duplicate detection
- Frequency-based filtering

---

## Real Applications

- **Top K Streaming:** Count with bounded memory
- **Duplicate Detection:** Constraint-based
- **Anagram Grouping:** Text processing
- **Frequency Analysis:** Data mining
