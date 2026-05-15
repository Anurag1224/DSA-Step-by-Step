// ============================================================================
// PROBLEM 5: Count Occurrences
// ============================================================================
//
// Problem Statement:
// Given an array and a target value, count how many times the target appears.
//
// Example:
//   Input: [1, 2, 2, 3, 2, 4, 2], target = 2
//   Output: 4
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
    
    // Count occurrences by traversing array
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            count++;
        }
    }
    
    cout << count << "\n";
    
    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Time Complexity: O(n) — traverse entire array
- Space Complexity: O(1) — constant space for counter

KEY LEARNING:
1. Simple counting problem — foundational
2. Works on unsorted array
3. Single pass sufficient

DRY RUN ([1, 2, 2, 3, 2, 4, 2], target = 2):
i=0: 1 != 2, count = 0
i=1: 2 == 2, count = 1
i=2: 2 == 2, count = 2
i=3: 3 != 2, count = 2
i=4: 2 == 2, count = 3
i=5: 4 != 2, count = 3
i=6: 2 == 2, count = 4
Output: 4

EDGE CASES:
- No occurrences: [1, 3, 4, 5], target = 2 → 0
- All same: [2, 2, 2], target = 2 → 3
- Single element: [5], target = 5 → 1

OPTIMIZATION:
For sorted array: Use binary search to find first and last
Time: O(log n) instead of O(n)
But for unsorted: No optimization possible
*/
