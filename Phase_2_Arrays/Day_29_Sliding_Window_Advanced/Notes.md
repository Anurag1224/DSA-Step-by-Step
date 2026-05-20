# 📝 Day 29: Sliding Window Advanced - Notes

## Key Patterns

### Pattern 1: Frequency Comparison
```cpp
// Compare two frequency maps
bool isPermutation(unordered_map<char, int>& target, 
                   unordered_map<char, int>& window) {
    for (auto& p : target) {
        if (window[p.first] != p.second) return false;
    }
    return true;
}

// Or use vector for small alphabets
vector<int> targetCount(26), windowCount(26);
// ... fill arrays ...
return targetCount == windowCount;  // O(1) comparison
```

---

### Pattern 2: Multi-Word Concatenation
```cpp
// Check if window contains all words
unordered_map<string, int> wordCount, windowCount;

for (string& word : words) {
    wordCount[word]++;
}

int wordLen = words[0].size();
int windowLen = words.size() * wordLen;

for (int i = 0; i + windowLen <= s.size(); i++) {
    // Extract window [i, i+windowLen)
    // Check if word concatenation matches
}
```

---

### Pattern 3: Multiple Conditions
```cpp
int required = 2;  // 2 conditions needed
int formed = 0;     // How many conditions met

for (int right = 0; right < n; right++) {
    // Add and check each condition
    if (condition1_met) formed++;
    if (condition2_met) formed++;
    
    while (left <= right && formed == required) {
        // Valid window
        left++;
    }
}
```

---

## Complexity Patterns

| Problem Type | Time | Space | Key Insight |
|-------------|------|-------|------------|
| Permutation | O(n) | O(26) | Frequency vectors |
| Concatenation | O(n*m) | O(m) | Word-based sliding |
| Multiple Cond | O(n) | O(n) | State tracking |

---

## Advanced Techniques

### 1. **Map Comparison Optimization**
- Use vector for small alphabets (O(1) compare)
- Use count variable for large alphabets
- Avoid full map iteration when possible

### 2. **Word-Level Sliding**
- Fix word boundaries
- Jump by word length
- Handle overlapping considerations

### 3. **Frequency Difference**
```cpp
// Track how many chars are "complete"
int matched = 0;
for (auto& p : required) {
    if (window[p.first] == p.second) matched++;
}
// matched == required.size() means window is valid
```

---

## Common Mistakes

1. **Map Equality:** Comparing maps is O(k) not O(1)
2. **Overflow:** Window can be larger than string
3. **Word Boundaries:** Don't break word patterns
4. **Frequency Reset:** Reset window counts when shrinking

---

## Interview Tips

✅ **Problem Understanding:** Clarify what "contains" means  
✅ **Edge Cases:** Empty strings, longer patterns, overlaps  
✅ **Optimization:** Choose right frequency data structure  
✅ **Variants:** Discuss multiple vs single matches  

---

## When to Use

- Check if string contains specific pattern
- Find shortest/longest with pattern
- Permutation/anagram problems
- Word concatenation validation
- Multiple frequency conditions

---

## Real Problem Examples

1. **Permutation in String:** Frequency vectors work
2. **Substring Concatenation:** Word-based iteration
3. **At Most K Distinct:** Counter incrementing
4. **Complex Conditions:** Multiple variables tracked

---

## Performance Tuning

- Avoid recreating maps (move initialization outside loop)
- Use pre-allocated vectors for fixed alphabets
- Break early when matches found
- Consider rolling hash for word problems
