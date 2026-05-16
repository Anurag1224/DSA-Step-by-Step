// ============================================================================
// PROBLEM 5: Ceiling of a Number (Binary Search)
// ============================================================================
//
// Problem Statement:
// Given a sorted array, find the smallest number ≥ target.
// Return -1 if no such number exists.
//
// Example:
//   Input: [1, 3, 5, 7, 9], target = 6
//   Output: 7 (smallest number ≥ 6)
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
    
    // Binary search for ceiling
    int left = 0, right = n - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] >= target) {
            result = arr[mid];  // Could be the answer
            right = mid - 1;    // Try to find smaller
        } else {
            left = mid + 1;
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
1. Ceiling: smallest number ≥ target
2. When arr[mid] >= target, it's a candidate (save and search left)
3. Mirror of floor logic

DRY RUN ([1, 3, 5, 7, 9], target = 6):
left=0, right=4, result=-1
mid=2: arr[2]=5 < 6, left=3
mid=4: arr[4]=9 >= 6, result=9, right=3
mid=3: arr[3]=7 >= 6, result=7, right=2
left > right, return 7 ✓

DRY RUN ([1, 3, 5, 7, 9], target = 0):
left=0, right=4, result=-1
mid=2: arr[2]=5 >= 0, result=5, right=1
mid=0: arr[0]=1 >= 0, result=1, right=-1
left > right, return 1 ✓

DRY RUN ([1, 3, 5, 7, 9], target = 10):
left=0, right=4, result=-1
mid=2: arr[2]=5 < 10, left=3
mid=4: arr[4]=9 < 10, left=5
left > right, return -1 ✓

FLOOR vs CEILING:
Floor (≤): arr[mid] <= target, search right
Ceiling (≥): arr[mid] >= target, search left
Opposite directions!
*/
