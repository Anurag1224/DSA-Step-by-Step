// ============================================================================
// PROBLEM 6: Find Position for Insertion (Insert Position)
// ============================================================================
//
// Problem Statement:
// Given a sorted array and a target, find the position where target should
// be inserted to keep array sorted. If target exists, return its position.
//
// Example:
//   Input: [1, 3, 5, 6], target = 5
//   Output: 2
//   
//   Input: [1, 3, 5, 6], target = 4
//   Output: 2 (position where 4 should be inserted)
//
// Constraints:
//   0 ≤ n ≤ 10^5
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
    
    // Binary search for insertion position
    int left = 0, right = n;  // Note: right = n, not n-1
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    cout << left << "\n";
    
    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Time Complexity: O(log n) — binary search
- Space Complexity: O(1) — constant space

KEY LEARNING:
1. 'left' ends up at the insertion position
2. right = n (includes position after last element)
3. Find first position where arr[mid] >= target

DRY RUN ([1, 3, 5, 6], target = 5):
left=0, right=4
mid=2: arr[2]=5 not < 5, right=2
mid=1: arr[1]=3 < 5, left=2
left == right, return 2 ✓

DRY RUN ([1, 3, 5, 6], target = 4):
left=0, right=4
mid=2: arr[2]=5 not < 4, right=2
mid=1: arr[1]=3 < 4, left=2
left == right, return 2 ✓

DRY RUN ([1, 3, 5, 6], target = 0):
left=0, right=4
mid=2: arr[2]=5 not < 0, right=2
mid=0: arr[0]=1 not < 0, right=0
left == right, return 0 ✓

DRY RUN ([1, 3, 5, 6], target = 7):
left=0, right=4
mid=2: arr[2]=5 < 7, left=3
mid=3: arr[3]=6 < 7, left=4
left == right, return 4 ✓

EDGE CASES:
- Empty array: return 0
- Insert at beginning: target smaller than all
- Insert at end: target larger than all
- Element already exists: return its position

WHY IT WORKS:
The invariant: all elements to the left of 'left' are < target
When loop ends: left = right = first position >= target
*/
