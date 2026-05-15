// ============================================================================
// PROBLEM 6: Second Largest Element
// ============================================================================
//
// Problem Statement:
// Given an array of integers (with at least 2 distinct elements),
// find the second largest element.
//
// Example:
//   Input: [3, 1, 4, 1, 5, 9, 2, 6]
//   Output: 6
//
// Constraints:
//   2 ≤ n ≤ 10^5
//   At least 2 distinct elements
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
    
    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    
    // Single pass to find both largest and second largest
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            // Current element is new largest
            secondLargest = largest;  // Old largest becomes second
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            // Current element is between second and first
            secondLargest = arr[i];
        }
    }
    
    cout << secondLargest << "\n";
    
    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Time Complexity: O(n) — single pass through array
- Space Complexity: O(1) — constant space

KEY LEARNING:
1. Maintain two variables for largest and second largest
2. Update in correct order (largest first, then second)
3. Handle duplicates: arr[i] != largest ensures distinct elements

DRY RUN ([3, 1, 4, 1, 5, 9, 2, 6]):
largest = INT_MIN, secondLargest = INT_MIN
i=0: 3 > INT_MIN → secondLargest = INT_MIN, largest = 3
i=1: 1 not > 3, 1 > INT_MIN and 1 != 3 → secondLargest = 1
i=2: 4 > 3 → secondLargest = 3, largest = 4
i=3: 1 not > 4, 1 < 3 → no change
i=4: 5 > 4 → secondLargest = 4, largest = 5
i=5: 9 > 5 → secondLargest = 5, largest = 9
i=6: 2 not > 9, 2 < 5 → no change
i=7: 6 not > 9, 6 > 5 and 6 != 9 → secondLargest = 6
Output: 6

EDGE CASES:
- [1, 2]: largest=2, secondLargest=1 → 1
- [5, 5, 5, 3]: with duplicates, secondLargest=3 → 3
- [10, 9, 8, 7]: largest=10, secondLargest=9 → 9

COMMON MISTAKE:
❌ arr[i] > secondLargest (without checking != largest)
   → Can assign largest value as second largest with duplicates
✅ arr[i] > secondLargest && arr[i] != largest
   → Ensures we get truly second largest
*/
