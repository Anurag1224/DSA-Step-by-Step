// ============================================================================
// PROBLEM 3: Linear Search
// ============================================================================
//
// Problem Statement:
// Given an array and a target value, find the index of the target.
// If not found, return -1.
//
// Example:
//   Input: [2, 4, 1, 9, 3], target = 9
//   Output: 3
//   
//   Input: [2, 4, 1, 9, 3], target = 5
//   Output: -1
//
// Constraints:
//   1 ≤ n ≤ 10^5
//   -10^9 ≤ arr[i] ≤ 10^9
//
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int target;
    cin >> target;
    
    // Linear search: check each element
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            cout << i << "\n";
            return 0;
        }
    }
    
    // Not found
    cout << -1 << "\n";
    
    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Time Complexity: O(n) in worst case, O(1) in best case
- Space Complexity: O(1) — constant space

KEY LEARNING:
1. Linear search works on unsorted arrays
2. Early return when found → saves iterations
3. Optimization: Binary search works only on sorted arrays

DRY RUN ([2, 4, 1, 9, 3], target = 9):
i=0: 2 != 9
i=1: 4 != 9
i=2: 1 != 9
i=3: 9 == 9 → return 3

DRY RUN ([2, 4, 1, 9, 3], target = 5):
i=0: 2 != 5
i=1: 4 != 5
i=2: 1 != 5
i=3: 9 != 5
i=4: 3 != 5
→ return -1

EDGE CASES:
- First element is target: [5, 1, 2] target=5 → 0
- Last element is target: [1, 2, 5] target=5 → 2
- Multiple occurrences: [1, 5, 5, 2] target=5 → 1 (first index)
- Empty? No (n ≥ 1)

OPTIMIZATION:
For sorted arrays, use binary search → O(log n)
*/
