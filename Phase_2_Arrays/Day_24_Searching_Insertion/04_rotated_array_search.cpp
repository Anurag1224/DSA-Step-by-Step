// ============================================================================
// PROBLEM 4: Search in Rotated Sorted Array
// ============================================================================
//
// Problem Statement:
// An integer array was originally sorted in ascending order, then rotated.
// Search for target in O(log n) time.
//
// Example:
//   Input: arr = [4, 5, 6, 7, 0, 1, 2], target = 0
//   Output: 4
//
// Constraints:
//   1 ≤ n ≤ 10^5
//   -10^9 ≤ arr[i] ≤ 10^9
//   All elements unique
//
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) return mid;
        
        // Determine which half is sorted
        if (arr[left] <= arr[mid]) {
            // Left half is sorted
            if (target >= arr[left] && target < arr[mid]) {
                right = mid - 1;  // Target in left half
            } else {
                left = mid + 1;   // Target in right half
            }
        } else {
            // Right half is sorted
            if (target > arr[mid] && target <= arr[right]) {
                left = mid + 1;   // Target in right half
            } else {
                right = mid - 1;  // Target in left half
            }
        }
    }
    
    return -1;
}

int main() {
    int n, target;
    cin >> n >> target;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << search(arr, target) << "\n";
    
    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Time Complexity: O(log n) — binary search
- Space Complexity: O(1)

KEY INSIGHT:
Even though rotated, one half is ALWAYS sorted!
Use this to eliminate half the search space each iteration.

ALGORITHM:
1. Find middle element
2. Check if it's target → return
3. Determine which half is sorted (compare endpoints)
4. If target in sorted half → search that half
5. Otherwise → search other half

DRY RUN ([4, 5, 6, 7, 0, 1, 2], target = 0):
left=0, right=6
mid=3: arr[3]=7 != 0
arr[0]=4 <= arr[3]=7? YES (left half sorted)
0 >= 4 && 0 < 7? NO
left = 4
---
left=4, right=6
mid=5: arr[5]=1 != 0
arr[4]=0 <= arr[5]=1? YES (left half sorted)
0 >= 0 && 0 < 1? YES
right = 4
---
left=4, right=4
mid=4: arr[4]=0 == 0 → return 4

EDGE CASES:
- Target at rotation point: [3, 1, 2] → search for 1 → index 1
- Single element: [1] → 0 if target=1, -1 otherwise
- Not found: [4, 5, 6, 7, 0, 1, 2], target=3 → -1
- First element: [4, 5, 6, 7, 0, 1, 2], target=4 → 0
- Last element: [4, 5, 6, 7, 0, 1, 2], target=2 → 6

FOLLOW-UP:
What if duplicates are allowed?
*/
