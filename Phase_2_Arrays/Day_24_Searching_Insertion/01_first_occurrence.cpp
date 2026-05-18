// ============================================================================
// PROBLEM 1: First Occurrence in Array
// ============================================================================
//
// Problem Statement:
// Find the first (leftmost) occurrence of target value in array.
//
// Example:
//   Input: arr = [1, 2, 2, 2, 3], target = 2
//   Output: 1 (first occurrence at index 1)
//
// Constraints:
//   1 ≤ n ≤ 10^5
//   -10^9 ≤ arr[i] ≤ 10^9
//
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // APPROACH 1: Linear Search (O(n))
    int result = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            result = i;
            break;  // First occurrence found
        }
    }
    
    cout << result << "\n";
    
    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Time Complexity: O(n) — worst case: element not found, traverse entire array
- Space Complexity: O(1) — only using indices

OPTIMIZATION (if array is sorted):
  Use Binary Search → O(log n)
  Keep moving left to find first occurrence

KEY LEARNING:
1. Break early to avoid unnecessary iterations
2. Use -1 for "not found" convention
3. First occurrence means leftmost position

DRY RUN ([1, 2, 2, 2, 3], target = 2):
i=0: arr[0]=1 != 2, continue
i=1: arr[1]=2 == 2, result=1, break
Output: 1

EDGE CASES:
- Element not found: [1, 3, 5], target=2 → -1
- All elements are target: [2, 2, 2] → 0
- Single element matching: [5] → 0
- Single element not matching: [5] → -1

FOLLOW-UP:
Can you optimize for sorted arrays?
Can you find the last occurrence?
*/
