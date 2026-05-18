// ============================================================================
// PROBLEM 3: Count Occurrences (Find Range)
// ============================================================================
//
// Problem Statement:
// Given sorted array with duplicates, count total occurrences of target.
// Efficiency matters here!
//
// Example:
//   Input: arr = [1, 2, 2, 2, 3], target = 2
//   Output: 3 (appears 3 times)
//
// Constraints:
//   1 ≤ n ≤ 10^5
//   Array is sorted
//
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // APPROACH 1: Simple Linear Search (O(n))
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) count++;
    }
    
    cout << count << "\n";
    
    return 0;
}

/*
OPTIMIZATION: Binary Search Approach (O(log n))
  1. Find first occurrence using binary search
  2. Find last occurrence using binary search
  3. Count = lastIndex - firstIndex + 1
  
  This reduces from O(n) to O(log n)!

BINARY SEARCH FOR FIRST OCCURRENCE:
int findFirst(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            result = mid;
            right = mid - 1;  // Keep searching left
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

BINARY SEARCH FOR LAST OCCURRENCE:
int findLast(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            result = mid;
            left = mid + 1;  // Keep searching right
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

COMPLEXITY COMPARISON:
- Linear Search: O(n)
- Binary Search: O(log n) — 1000x faster for n=10^6

DRY RUN ([1, 2, 2, 2, 3], target = 2):
count = 0
i=0: arr[0]=1 != 2
i=1: arr[1]=2 == 2, count=1
i=2: arr[2]=2 == 2, count=2
i=3: arr[3]=2 == 2, count=3
i=4: arr[4]=3 != 2
Output: 3

EDGE CASES:
- Not found: [] → 0
- All elements are target: [2, 2, 2] → 3
- Single element: [2] → 1
- Empty range: [1, 3, 5] → 0

INTERVIEW HINT:
"I'll start with linear search O(n), but since array is sorted,
we can optimize to O(log n) using binary search boundaries!"
*/
