// ============================================================================
// PROBLEM 2: Find Maximum Element
// ============================================================================
//
// Problem Statement:
// Given an array of integers, find the maximum element.
//
// Example:
//   Input: [3, 1, 4, 1, 5, 9, 2, 6]
//   Output: 9
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
    
    // Initialize max with first element
    int maxElement = arr[0];
    
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    
    cout << maxElement << "\n";
    
    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Time Complexity: O(n) — single pass through array
- Space Complexity: O(1) — constant space

KEY LEARNING:
1. Always initialize with first element, not INT_MIN
2. Single pass is optimal for finding max
3. Works with negative numbers too

DRY RUN ([3, 1, 4, 1, 5, 9, 2, 6]):
maxElement = 3
i=1: 1 < 3, maxElement = 3
i=2: 4 > 3, maxElement = 4
i=3: 1 < 4, maxElement = 4
i=4: 5 > 4, maxElement = 5
i=5: 9 > 5, maxElement = 9
i=6: 2 < 9, maxElement = 9
i=7: 6 < 9, maxElement = 9
Output: 9

EDGE CASES:
- Single element: [5] → 5
- All same: [3, 3, 3] → 3
- Negative numbers: [-5, -2, -10] → -2
- Unsorted: [1, 9, 2, 8, 3] → 9

COMMON MISTAKE:
❌ Initialize maxElement = INT_MIN
   → Can cause issues in some systems
✅ Initialize maxElement = arr[0]
   → Always safe and correct
*/
