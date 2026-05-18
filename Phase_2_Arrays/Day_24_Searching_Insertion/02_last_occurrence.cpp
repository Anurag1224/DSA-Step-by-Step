// ============================================================================
// PROBLEM 2: Last Occurrence in Array
// ============================================================================
//
// Problem Statement:
// Find the last (rightmost) occurrence of target value in array.
//
// Example:
//   Input: arr = [1, 2, 2, 2, 3], target = 2
//   Output: 3 (last occurrence at index 3)
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
    
    // APPROACH: Linear Search from Right (O(n))
    int result = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == target) {
            result = i;
            break;  // Last occurrence found
        }
    }
    
    cout << result << "\n";
    
    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Time Complexity: O(n) — worst case: element not found
- Space Complexity: O(1)

OPTIMIZATION (if array is sorted):
  Use Binary Search from right → O(log n)
  Keep moving right to find last occurrence

KEY LEARNING:
1. Iterate from right to left for last occurrence
2. Break early when found
3. Compare: First vs Last Occurrence strategies

DRY RUN ([1, 2, 2, 2, 3], target = 2):
i=4: arr[4]=3 != 2
i=3: arr[3]=2 == 2, result=3, break
Output: 3

PATTERN:
First Occurrence: Iterate LEFT to RIGHT, BREAK on first match
Last Occurrence:  Iterate RIGHT to LEFT, BREAK on first match

EDGE CASES:
- Not found: [1, 3, 5], target=2 → -1
- All same: [2, 2, 2] → 2
- Only at start: [2, 1, 3] → 0
- Only at end: [1, 3, 2] → 2

VARIATION:
What if you can't iterate from right? Use forward loop with result update:
int result = -1;
for (int i = 0; i < n; i++) {
    if (arr[i] == target) result = i;  // Keep updating
}
*/
