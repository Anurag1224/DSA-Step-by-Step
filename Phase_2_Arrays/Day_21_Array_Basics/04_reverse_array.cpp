// ============================================================================
// PROBLEM 4: Reverse an Array
// ============================================================================
//
// Problem Statement:
// Given an array, reverse it in-place (without extra array).
//
// Example:
//   Input: [1, 2, 3, 4, 5]
//   Output: [5, 4, 3, 2, 1]
//
// Constraints:
//   1 ≤ n ≤ 10^5
//   Array can contain any integers
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
    
    // Two pointer approach: swap from ends moving towards center
    int left = 0, right = n - 1;
    
    while (left < right) {
        // Swap elements at left and right
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    
    // Print reversed array
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << " ";
    }
    cout << "\n";
    
    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Time Complexity: O(n) — visit each element once
- Space Complexity: O(1) — in-place reversal, no extra array

KEY LEARNING:
1. Two pointer approach: left and right from ends
2. In-place modification saves space
3. Stop when left >= right (covers both even and odd lengths)

DRY RUN ([1, 2, 3, 4, 5]):
left=0, right=4: swap(1, 5) → [5, 2, 3, 4, 1]
left=1, right=3: swap(2, 4) → [5, 4, 3, 2, 1]
left=2, right=2: stop (left == right)
Output: [5, 4, 3, 2, 1]

DRY RUN ([1, 2, 3, 4]):
left=0, right=3: swap(1, 4) → [4, 2, 3, 1]
left=1, right=2: swap(2, 3) → [4, 3, 2, 1]
left=2, right=1: stop (left > right)
Output: [4, 3, 2, 1]

EDGE CASES:
- Single element: [5] → [5]
- Two elements: [1, 2] → [2, 1]
- Empty? No (n ≥ 1)

COMPARISON:
❌ Using built-in reverse() hides the concept
✅ Manual swap teaches two-pointer technique
*/
