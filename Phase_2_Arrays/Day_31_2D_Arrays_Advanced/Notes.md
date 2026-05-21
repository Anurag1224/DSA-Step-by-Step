# 📝 Day 31: 2D Arrays Advanced - Notes

## Key Patterns

### Pattern 1: Searching in Rotated Matrix
```cpp
// Find rotation point first
int findRotationPoint(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int left = 0, right = n - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (matrix[mid][0] > matrix[right][0]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}
```

---

### Pattern 2: Row-Column Sorted Search
```cpp
// Start from top-right or bottom-left
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int row = 0, col = n - 1;
    
    while (row < m && col >= 0) {
        if (matrix[row][col] == target) return true;
        if (matrix[row][col] > target) {
            col--;  // Move left
        } else {
            row++;  // Move down
        }
    }
    return false;
}
```

---

### Pattern 3: Island/Connected Component Count
```cpp
// DFS for connected components
void dfs(vector<vector<int>>& grid, int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n) return;
    if (grid[i][j] != '1') return;
    
    grid[i][j] = '0';  // Mark visited
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
}

int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                dfs(grid, i, j);
                count++;
            }
        }
    }
    return count;
}
```

---

## Complexity Analysis

| Problem | Time | Space | Key Insight |
|---------|------|-------|------------|
| Rotated Search | O(log m*n) | O(1) | Find pivot, binary search |
| Row-Col Search | O(m+n) | O(1) | Start corner |
| Island Count | O(m*n) | O(m*n) | DFS + marking |
| Max Area | O(m*n) | O(m*n) | DFS returns area |

---

## Common Mistakes

1. **Boundary Conditions:** Check before accessing
2. **Visited Marking:** Modify matrix or use set
3. **Starting Point:** Wrong corner leads to inefficiency
4. **Recursion Depth:** Stack overflow on large matrices

---

## Interview Tips

✅ **Pivot Finding:** Essential for rotated search  
✅ **Corner Strategy:** Top-right or bottom-left optimal  
✅ **Graph View:** Matrix as implicit graph  
✅ **Follow-up:** Multiple islands? Obstacles?  

---

## When to Use

- Searching in special matrices
- Connected component problems
- Maximum area/perimeter calculations
- Path finding with obstacles

---

## Optimization Thoughts

- BFS vs DFS: BFS uses more space but can be iterative
- Marking vs Set: Set is safer, marking is faster
- Early termination: Sometimes possible in search
- Space optimization: Could use bit packing for visited
