# 📝 Day 45: Mastery Review & Capstone - Notes

## Phase 2 Technique Summary

### Core Techniques (Master These)

**1. Two Pointers**
- Time: O(n), Space: O(1)
- Uses: Sorting, partitioning, palindromes
- Key: Convergence property

**2. Sliding Window**
- Fixed: O(n) with deque for min/max
- Variable: O(n) with frequency tracking
- Uses: Substring problems, frequency patterns

**3. Prefix Sum**
- Build: O(n), Query: O(1)
- Extensions: 2D, XOR, modulo operations
- Uses: Range queries, cumulative operations

**4. Two-Pass Algorithms**
- Left-right passes: Kadane's, best stock
- Bottom-up DP: Standard approach
- Time: O(n), Space: O(n) or O(1)

---

## Pattern Recognition

### Question → Technique Mapping

**"Find subarray/substring..."**
→ Sliding window or prefix sum

**"Two sum / pairs..."**
→ Two pointer or hash map

**"Maximum/minimum with condition..."**
→ DP, greedy, or sliding window

**"Count/frequency..."**
→ Hash map or bucket approach

**"In-place modification..."**
→ Two pointer partitioning

**"Rotation/rearrangement..."**
→ Reversal trick or cyclic iteration

**"Matrix traversal..."**
→ Layer-based or directional iteration

---

## Complexity Cheat Sheet

| Task | Time | Space |
|------|------|-------|
| Search sorted | O(log n) | O(1) |
| Two pointer | O(n) | O(1) |
| Sliding window | O(n) | O(k) |
| Prefix sum | O(n) build + O(1) query | O(n) |
| Sort + search | O(n log n) | O(1) |
| Hash map | O(n) avg, O(n²) worst | O(n) |
| DP | O(n) to O(n³) | O(n) to O(n²) |

---

## Edge Case Checklist

- [ ] Empty array
- [ ] Single element
- [ ] All same elements
- [ ] Negative numbers
- [ ] Zeros
- [ ] Large values (overflow)
- [ ] Duplicate elements
- [ ] Boundary conditions
- [ ] Integer division/modulo
- [ ] Circular/wraparound

---

## Interview Success Factors

**Before Coding:**
1. Clarify problem constraints
2. Discuss examples and edge cases
3. Explain your approach
4. Analyze time/space complexity

**While Coding:**
1. Write clean, readable code
2. Add comments for logic
3. Handle edge cases
4. Test with examples

**After Coding:**
1. Verify with test cases
2. Discuss optimizations
3. Explain time/space tradeoffs
4. Answer follow-up questions

---

## Common Follow-Up Questions

**"Can you optimize space?"**
→ In-place modification, bit manipulation

**"What if array is modified?"**
→ Consider segment trees, Fenwick trees

**"Handle duplicates?"**
→ Adjust comparisons, use sets

**"Multiple queries?"**
→ Preprocessing, prefix sums, segment trees

**"Very large array?"**
→ O(1) space if possible, streaming algorithms

---

## Problem-Solving Framework

```
1. Understand → Examples → Constraints
2. Brute Force → Analyze Complexity
3. Identify Pattern → Apply Technique
4. Optimize → Handle Edge Cases
5. Test → Explain Solution
```

---

## Common Pitfalls to Avoid

❌ Integer overflow (use long long)
❌ Off-by-one errors (test boundaries)
❌ Modifying input (ask permission)
❌ Not handling edge cases
❌ Assuming sorted array
❌ Forgetting about negative numbers
❌ Not testing your solution
❌ Over-complicating simple problems

---

## Phase 2 Mastery Indicators

You've mastered Phase 2 when you can:

✅ Recognize when to use two pointers
✅ Implement sliding window patterns
✅ Apply prefix sums for optimization
✅ Solve matrix problems efficiently
✅ Identify subarray vs subsequence
✅ Handle interval problems
✅ Manage circular arrays
✅ Use hash maps effectively
✅ Optimize space to O(1) when possible
✅ Explain your approach clearly

---

## Next Phase Preview

**Phase 3: Linked Lists**
- Node-based data structures
- Pointers and references
- Cycle detection
- Manipulation techniques

**Phase 4: Trees**
- Binary search trees
- Tree traversals
- DFS and BFS
- Balance and optimization

---

## Resources for Deeper Learning

**Practice:**
- LeetCode: Arrays, Medium-Hard
- GeeksforGeeks: Array problems
- HackerRank: Array manipulation

**Theory:**
- CLRS: Algorithmic foundations
- Algorithm Design Manual
- Online courses on algorithms

---

## Final Thoughts

Arrays are the foundation of CS. Master these:
- Time-space tradeoffs
- Pattern recognition
- Clean code practices
- Problem-solving mindset

**The goal: Solve ANY array problem with confidence! 🎯**
