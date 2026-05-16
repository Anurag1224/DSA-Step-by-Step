// ============================================================================
// PROBLEM 1: Binary Search - First Occurrence
// ============================================================================
//
// Problem Statement:
// Given a sorted array, find the first (leftmost) occurrence of target.
// Return -1 if not found.
//
// Example:
//   Input: [1, 2, 2, 2, 3, 4, 5], target = 2
//   Output: 1
//
// Constraints:
//   1 ≤ n ≤ 10^5
//   Array is sorted in ascending order
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
    
    // Binary search for first occurrence
    int left = 0, right = n - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            result = mid;  // Found, but keep searching left
            right = mid - 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << result << "\n";
    
    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Time Complexity: O(log n) — binary search
- Space Complexity: O(1) — constant space

KEY LEARNING:
1. When found, keep searching left to find FIRST occurrence
2. Update result but don't return immediately
3. Works only on sorted arrays

DRY RUN ([1, 2, 2, 2, 3, 4, 5], target = 2):
left=0, right=6, result=-1
mid=3: arr[3]=2 == 2, result=3, right=2
mid=1: arr[1]=2 == 2, result=1, right=0
mid=0: arr[0]=1 < 2, left=1
left > right, return 1 ✓

EDGE CASES:
- Not found: [1, 3, 5], target=2 → -1
- First element: [2, 2, 2], target=2 → 0
- Last element: [1, 2, 3], target=3 → 2
- Single element: [5], target=5 → 0
*/
