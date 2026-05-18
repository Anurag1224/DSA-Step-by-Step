// ============================================================================
// PROBLEM 6: Search in Array of Unknown Size
// ============================================================================
//
// Problem Statement:
// Given an unsorted array of unknown size (can't call .size() directly),
// find position of target. Constraint: Can only access elements.
//
// Example:
//   Input: arr (unknown size), target = 9
//   Output: 2 (assuming arr = [1, 5, 9, 13...])
//
// Note: This simulates searching in infinite arrays or streams.
//
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

// Simulating unknown size array access
vector<int> arr;  // In real scenario, this would be external

// Function to safely access element
int getElement(int index) {
    if (index >= arr.size()) return INT_MAX;  // Out of bounds
    return arr[index];
}

int main() {
    int n, target;
    cin >> n >> target;
    
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // APPROACH: Two-Step Binary Search
    // Step 1: Find the range by exponential jump
    int bound = 1;
    while (getElement(bound) < target) {
        bound *= 2;  // Jump by power of 2
    }
    
    // Step 2: Binary search within [bound/2, bound]
    int left = bound / 2;
    int right = bound;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int mid_val = getElement(mid);
        
        if (mid_val == target) {
            result = mid;
            break;
        } else if (mid_val < target) {
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
- Time Complexity: O(log n) — exponential search + binary search
- Space Complexity: O(1)

ALGORITHM:
1. Exponential Search: Keep doubling index until element >= target
2. Binary Search: Search within the found range
3. Combined: O(log n) where n is position of element

KEY INSIGHT:
When array size unknown, use exponential jumps to find boundary,
then standard binary search in that range.

DRY RUN (simulating [1, 3, 5, 7, 9], target = 9):
bound=1: getElement(1)=3 < 9, bound=2
bound=2: getElement(2)=5 < 9, bound=4
bound=4: getElement(4)=9 >= 9, STOP

Binary search in [2, 4]:
left=2, right=4
mid=3: getElement(3)=7 < 9, left=4
mid=4: getElement(4)=9 == 9 → return 4

EDGE CASES:
- Target not in array: Returns -1
- Very large array: Still O(log n) due to exponential+binary
- Single element: Handled correctly
- Target at start: Quickly found in first iterations

REAL-WORLD USE:
- Searching in log files (new data appended continuously)
- Searching in streams (don't know total size)
- API pagination (don't know total items)

WHY EXPONENTIAL + BINARY:
- Exponential alone: Too slow if target far away but exists
- Binary alone: Need to know size first
- Combined: Best of both worlds!
*/
