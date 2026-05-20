# 📝 Day 28: Sliding Window (Variable Size) - Notes

## Key Patterns

### Pattern 1: Expand Right, Shrink Left
```cpp
int left = 0;
for (int right = 0; right < n; right++) {
    // Add arr[right] to window
    
    // Shrink from left if condition violated
    while (left <= right && !isValid()) {
        // Remove arr[left]
        left++;
    }
    
    // Process valid window [left, right]
}
```
**Key:** Window shrinks as needed

---

### Pattern 2: Frequency Map Tracking
```cpp
unordered_map<char, int> window, required;

// Initialize required
for (char c : t) required[c]++;

int left = 0;
for (int right = 0; right < s.size(); right++) {
    window[s[right]]++;
    
    // Shrink while valid
    while (left <= right && allConditionsMet()) {
        // Update answer
        left++;
    }
}
```

---

### Pattern 3: At Most K Pattern
```cpp
// atMost(k) - atMost(k-1) = exactly k distinct
int atMostK(string s, int k) {
    unordered_map<char, int> count;
    int left = 0, result = 0;
    
    for (int right = 0; right < s.size(); right++) {
        count[s[right]]++;
        
        while (count.size() > k) {
            count[s[left]]--;
            if (count[s[left]] == 0) count.erase(s[left]);
            left++;
        }
        
        result += right - left + 1;
    }
    
    return result;
}

int exactlyK(string s, int k) {
    return atMostK(s, k) - atMostK(s, k - 1);
}
```

---

## Complexity Analysis

| Approach | Time | Space | Use Case |
|----------|------|-------|----------|
| Variable Window | O(n) | O(k) | Substring problems |
| Two Pass | O(2n) | O(k) | Exactly k pattern |
| Hash Map | O(n) | O(26) | Alphabet size |

---

## Common Mistakes

1. **Shrinking Logic:** Shrink correctly to maintain invariant
2. **Comparison:** Map comparison is expensive O(k)
3. **Frequency Update:** Erase when count becomes 0
4. **Window Validity:** Know exact condition for validity

---

## Interview Tips

✅ **Recognize Pattern:** Multiple condition problems  
✅ **Frequency Tracking:** Essential for substring problems  
✅ **Difference Trick:** atMost(k) - atMost(k-1) pattern  
✅ **State Management:** Track what you need to validate  

---

## When to Use

- Find substring/subarray with properties
- Min/max length requirements
- Frequency-based conditions
- Multiple condition validation

---

## Problem Categories

1. **Min Window:** Find shortest substring with property
2. **Max Window:** Find longest substring with property
3. **Count Windows:** Count all valid substrings
4. **Frequency:** Distinct characters, at most k...

---

## Key Insight

Variable window **shrinks actively** unlike fixed window.
Two pointers move independently based on conditions.
