// ============================================================================
// PROBLEM 5: Search for a Range / Insert Position
// ============================================================================
//
// Problem Statement:
// Given a sorted array, find the position where target should be inserted
// to keep array sorted. If target exists, return its index.
//
// Example:
//   Input: arr = [1, 3, 5, 6], target = 5
//   Output: 2
//   
//   Input: arr = [1, 3, 5, 6], target = 4
//   Output: 2 (insert position to maintain order)
//
// Constraints:
//   1 ≤ n ≤ 10^5
//   Array is sorted
//
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& arr, int target) {
    int left = 0, right = arr.size();
    
    // Find leftmost position >= target
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}

int main() {
    int n, target;
    cin >> n >> target;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << searchInsert(arr, target) << "\n";
    
    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Time Complexity: O(log n) — binary search
- Space Complexity: O(1)

KEY INSIGHT:
This is the "lower_bound" operation!
Find leftmost position where element >= target can be placed.

ALGORITHM:
Use binary search with inclusive left, exclusive right.
Return the position where target should be inserted.

DRY RUN ([1, 3, 5, 6], target = 4):
left=0, right=4
mid=2: arr[2]=5 < 4? NO
right=2
---
left=0, right=2
mid=1: arr[1]=3 < 4? YES
left=2
---
left=2, right=2
→ return 2
Insertion: [1, 3, 4, 5, 6]

DRY RUN ([1, 3, 5, 6], target = 5):
left=0, right=4
mid=2: arr[2]=5 < 5? NO
right=2
---
left=0, right=2
mid=1: arr[1]=3 < 5? YES
left=2
---
left=2, right=2
→ return 2
Result: Position 2 where 5 already exists

EDGE CASES:
- Insert before all: [1, 3, 5], target=0 → 0
- Insert after all: [1, 3, 5], target=6 → 3
- Insert between: [1, 3, 5], target=4 → 2
- Exact match at start: [1, 3, 5], target=1 → 0
- Exact match at end: [1, 3, 5], target=5 → 2

STL EQUIVALENT:
lower_bound(arr.begin(), arr.end(), target) - arr.begin()
*/
