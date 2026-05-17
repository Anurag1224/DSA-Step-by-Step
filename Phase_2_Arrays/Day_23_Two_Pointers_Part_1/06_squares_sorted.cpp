// ============================================================================
// PROBLEM 6: Squares of Sorted Array (Two Pointers)
// ============================================================================
//
// Problem Statement:
// Given a sorted array that may contain negative numbers,
// return an array of squares sorted in ascending order.
//
// Example:
//   Input: [-4, -1, 0, 3, 10]
//   Output: [0, 1, 9, 16, 100]
//
// Constraints:
//   1 ≤ n ≤ 10^5
//   Array is sorted but contains negative numbers
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
    
    vector<int> result(n);
    int left = 0, right = n - 1;
    
    // Fill result array from RIGHT to LEFT
    for (int k = n - 1; k >= 0; k--) {
        int leftSquare = arr[left] * arr[left];
        int rightSquare = arr[right] * arr[right];
        
        if (leftSquare > rightSquare) {
            result[k] = leftSquare;
            left++;
        } else {
            result[k] = rightSquare;
            right--;
        }
    }
    
    // Print result
    for (int i = 0; i < n; i++) {
        cout << result[i];
        if (i < n - 1) cout << \" \";
    }
    cout << \"\\n\";
    
    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Time Complexity: O(n) — single pass
- Space Complexity: O(n) — for result array

KEY LEARNING:
1. Negative numbers have large squares!
2. Fill result from RIGHT (largest) to LEFT
3. Compare squares from both ends, pick larger
4. This ensures sorted order

WHY IT WORKS:
In sorted array with negatives:
- Largest squares are at ends (far left or far right)
- Middle has smallest squares
- So fill result array backwards!

DRY RUN ([-4, -1, 0, 3, 10]):
left=0 (-4), right=4 (10)
k=4: 16 vs 100, result[4]=100, right=3
k=3: 16 vs 9, result[3]=16, left=1
k=2: 1 vs 9, result[2]=9, right=2
k=1: 1 vs 0, result[1]=1, left=2
k=0: 0 vs 0, result[0]=0
Result: [0, 1, 9, 16, 100] ✓

TRICK:
Fill result array backwards!
result[k] = ... for k from n-1 down to 0
This ensures final result is sorted!

INTUITION:
Without this trick, merging sorted ends is hard
By working backwards, we naturally get sorted order
*/
