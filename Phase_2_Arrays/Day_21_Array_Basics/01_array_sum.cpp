// ============================================================================
// PROBLEM 1: Array Sum (Traverse and Sum)
// ============================================================================
//
// Problem Statement:
// Given an array of integers, find the sum of all elements.
//
// Example:
//   Input: [1, 2, 3, 4, 5]
//   Output: 15
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
    
    long long sum = 0;  // Use long long to prevent overflow
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    
    cout << sum << "\n";
    
    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Time Complexity: O(n) — iterate through array once
- Space Complexity: O(1) — only using constant space for sum

KEY LEARNING:
1. Always use long long when summing to prevent overflow
2. Traversal is fundamental — master the loop pattern
3. One pass solution is optimal for this problem

DRY RUN ([1, 2, 3, 4, 5]):
i=0: sum = 0 + 1 = 1
i=1: sum = 1 + 2 = 3
i=2: sum = 3 + 3 = 6
i=3: sum = 6 + 4 = 10
i=4: sum = 10 + 5 = 15
Output: 15

EDGE CASES:
- Single element array: [5] → 5
- Negative numbers: [-1, -2, -3] → -6
- All zeros: [0, 0, 0] → 0
- Large sum: [10^9, 10^9] → overflow without long long!
*/
