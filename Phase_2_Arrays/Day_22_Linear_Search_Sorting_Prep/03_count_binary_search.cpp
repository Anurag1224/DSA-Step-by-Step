// ============================================================================
// PROBLEM 3: Count Occurrences (Using Binary Search)
// ============================================================================
//
// Problem Statement:
// Given a sorted array, count how many times target appears.
// Use binary search for efficiency.
//
// Example:
//   Input: [1, 2, 2, 2, 3, 4, 5], target = 2
//   Output: 3
//
// Constraints:
//   1 ≤ n ≤ 10^5
//   Array is sorted in ascending order
//
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int findFirst(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            result = mid;
            right = mid - 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int findLast(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            result = mid;
            left = mid + 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int target;
    cin >> target;
    
    int first = findFirst(arr, target);
    if (first == -1) {
        cout << 0 << "\n";
        return 0;
    }
    
    int last = findLast(arr, target);
    int count = last - first + 1;
    
    cout << count << "\n";
    
    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Time Complexity: O(log n) — two binary searches
- Space Complexity: O(1) — constant space

KEY LEARNING:
1. Count = last_index - first_index + 1
2. Combine first and last occurrence searches
3. Much faster than linear scan: O(log n) vs O(n)

DRY RUN ([1, 2, 2, 2, 3, 4, 5], target = 2):
first = 1 (first occurrence at index 1)
last = 3 (last occurrence at index 3)
count = 3 - 1 + 1 = 3 ✓

DRY RUN ([1, 3, 5], target = 2):
first = -1 (not found)
return 0 ✓

EDGE CASES:
- Not found: count = 0
- Single occurrence: first == last, count = 1
- All occurrences: first = 0, last = n-1
- Array size 1: [5], target=5, count = 1

OPTIMIZATION vs LINEAR:
Linear: O(n) - check all elements
Binary: O(log n) - only 2 binary searches
Benefit grows with array size!
*/
