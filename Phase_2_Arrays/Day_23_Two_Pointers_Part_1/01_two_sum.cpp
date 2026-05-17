// ============================================================================
// PROBLEM 1: Two Sum (Sorted Array)
// ============================================================================
//
// Problem Statement:
// Given a sorted array, find two numbers that add up to target.
// Return indices of the two numbers.
//
// Example:
//   Input: [2, 7, 11, 15], target = 9
//   Output: [0, 1] (indices of 2 and 7)
//
// Constraints:
//   2 ≤ n ≤ 10^5
//   Array is sorted in ascending order
//   Exactly one solution exists
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
    
    // Two pointers approach
    int left = 0, right = n - 1;
    
    while (left < right) {
        int sum = arr[left] + arr[right];
        
        if (sum == target) {
            cout << left << " " << right << "\n";
            return 0;
        } else if (sum < target) {
            left++;  // Need larger sum
        } else {
            right--;  // Need smaller sum
        }
    }
    
    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Time Complexity: O(n) — single pass with two pointers
- Space Complexity: O(1) — only using two pointers
- Much better than O(n²) brute force!

KEY LEARNING:
1. Start with left at beginning, right at end
2. If sum too small, move left pointer right
3. If sum too large, move right pointer left
4. This works because array is sorted!

DRY RUN ([2, 7, 11, 15], target = 9):
left=0, right=3
sum = 2+15 = 17 > 9, right=2
sum = 2+11 = 13 > 9, right=1
sum = 2+7 = 9 == 9, return [0, 1] ✓

WHY TWO POINTERS WORK:
- If arr[left] + arr[right] < target:
  We need larger sum, so increase left
- If arr[left] + arr[right] > target:
  We need smaller sum, so decrease right
- ONLY works on sorted array!

EDGE CASES:
- Array size 2: [1, 2], target=3 → [0, 1]
- Large numbers: handled with int
- Sum near boundaries: still works
*/
