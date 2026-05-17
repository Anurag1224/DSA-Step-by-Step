// ============================================================================
// PROBLEM 4: Container With Most Water (Two Pointers)
// ============================================================================
//
// Problem Statement:
// Given an array of heights, find two lines that together with x-axis
// form a container with the most water.
// Area = min(height[i], height[j]) * (j - i)
//
// Example:
//   Input: [1, 8, 6, 2, 5, 4, 8, 3, 7]
//   Output: 49 (8 and 7 with distance 8 between them: 7 * 8 = 56... recalc)
//           Actually: index 1 (height=8) and index 8 (height=7)
//           Area = min(8,7) * (8-1) = 7 * 7 = 49
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
    
    // Two pointers from both ends
    int left = 0, right = n - 1;
    int maxArea = 0;
    
    while (left < right) {
        // Calculate area
        int width = right - left;
        int height = min(arr[left], arr[right]);
        int area = width * height;
        
        maxArea = max(maxArea, area);
        
        // Move the pointer with smaller height
        // (moving the taller one won't help anyway)
        if (arr[left] < arr[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    cout << maxArea << \"\\n\";
    
    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Time Complexity: O(n) — single pass
- Space Complexity: O(1) — only using pointers

KEY LEARNING:
1. Area = min(left_height, right_height) * distance
2. Start from maximum distance
3. Move the pointer with SMALLER height
   (moving taller one can only reduce area)

DRY RUN ([1, 8, 6, 2, 5, 4, 8, 3, 7]):
left=0 (h=1), right=8 (h=7)
area = min(1,7) * 8 = 8, move left (1 is smaller)
left=1 (h=8), right=8 (h=7)
area = min(8,7) * 7 = 49, move right (7 is smaller)
left=1 (h=8), right=7 (h=3)
area = min(8,3) * 6 = 18, move right (3 is smaller)
... continues ...
maxArea = 49 ✓

WHY MOVE SMALLER:
If we have [5, 2] and [5, 8]:
- Move the 2: get [5, 8], might improve
- Move the 5: get [2, 8], definitely worse

GREEDY INSIGHT:
At each step, we keep the pointer with larger height
because that gives us the best chance of improvement
when we move the smaller pointer.
*/
