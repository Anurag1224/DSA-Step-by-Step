# 📝 Day 36: Interval Problems - Notes

## Key Patterns

### Pattern 1: Merge Overlapping Intervals
```cpp
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};
    
    // Sort by start time
    sort(intervals.begin(), intervals.end());
    
    vector<vector<int>> result;
    result.push_back(intervals[0]);
    
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= result.back()[1]) {
            // Overlapping: merge
            result.back()[1] = max(result.back()[1], intervals[i][1]);
        } else {
            // Non-overlapping: add new
            result.push_back(intervals[i]);
        }
    }
    
    return result;
}
```

---

### Pattern 2: Insert Interval
```cpp
vector<vector<int>> insert(vector<vector<int>>& intervals, 
                           vector<int>& newInterval) {
    vector<vector<int>> result;
    int i = 0;
    
    // Add all intervals before newInterval
    while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
        result.push_back(intervals[i++]);
    }
    
    // Merge overlapping
    while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    result.push_back(newInterval);
    
    // Add remaining
    while (i < intervals.size()) {
        result.push_back(intervals[i++]);
    }
    
    return result;
}
```

---

### Pattern 3: Greedy Scheduling
```cpp
// Maximum non-overlapping intervals (activity selection)
int maxNonOverlapping(vector<vector<int>>& intervals) {
    // Sort by end time
    sort(intervals.begin(), intervals.end(), 
         [](auto& a, auto& b) { return a[1] < b[1]; });
    
    int count = 0, lastEnd = INT_MIN;
    
    for (auto& interval : intervals) {
        if (interval[0] >= lastEnd) {
            count++;
            lastEnd = interval[1];
        }
    }
    
    return count;
}
```

---

## Complexity Analysis

| Operation | Time | Space | Key Insight |
|-----------|------|-------|------------|
| Merge | O(n log n) | O(n) | Sort, then single pass |
| Insert | O(n) | O(n) | Three phases |
| Schedule | O(n log n) | O(1) | Sort by end time |

---

## Common Mistakes

1. **Boundary Conditions:** < vs <= in overlapping
2. **Sorting Key:** End time vs start time matters
3. **Edge Cases:** Single interval, all overlap, no overlap
4. **Greedy Choice:** Why end time? (Leaves more room)

---

## Interview Tips

✅ **Merge Logic:** When exactly do intervals overlap?  
✅ **Greedy Proof:** Why select by end time?  
✅ **Edge Cases:** Empty, single, duplicate  
✅ **Follow-up:** What if intervals have weights?  

---

## When to Use

- Merging overlapping time slots
- Interval scheduling problems
- Room reservation systems
- Calendar event management

---

## Advanced Variations

- **Weighted intervals:** Max value scheduling
- **Meeting rooms:** Minimum rooms needed
- **Conflict resolution:** Greedy selection
- **Data stream merging:** Online algorithm
