// ============================================================================
// PROBLEM 5: Merge Sorted Arrays (Two Pointers)
// ============================================================================
//
// Problem Statement:
// Given two sorted arrays, merge them into one sorted array.
//
// Example:
//   Input: [1, 3, 5], [2, 4, 6]
//   Output: [1, 2, 3, 4, 5, 6]
//
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    
    vector<int> arr1(m);
    for (int i = 0; i < m; i++) {
        cin >> arr1[i];
    }
    
    vector<int> arr2(n);
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }
    
    vector<int> merged(m + n);
    int i = 0, j = 0, k = 0;
    
    // Two pointer merge
    while (i < m && j < n) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }
    
    // Add remaining elements from arr1
    while (i < m) {
        merged[k++] = arr1[i++];
    }
    
    // Add remaining elements from arr2
    while (j < n) {
        merged[k++] = arr2[j++];
    }
    
    // Print merged array
    for (int i = 0; i < m + n; i++) {
        cout << merged[i];
        if (i < m + n - 1) cout << \" \";
    }
    cout << \"\\n\";
    
    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Time Complexity: O(m + n) — visit each element once
- Space Complexity: O(m + n) — for merged array

KEY LEARNING:
1. Use three pointers: i, j, k
2. Compare arr1[i] and arr2[j], pick smaller
3. Add remaining elements from whichever array is left

DRY RUN ([1, 3, 5], [2, 4, 6]):
i=0, j=0, k=0
1 <= 2, merged[0]=1, i=1, k=1
3 > 2, merged[1]=2, j=1, k=2
3 <= 4, merged[2]=3, i=2, k=3
5 > 4, merged[3]=4, j=2, k=4
5 <= 6, merged[4]=5, i=3, k=5
j < n, merged[5]=6, j=3, k=6
Result: [1, 2, 3, 4, 5, 6] ✓

MERGE SORT FOUNDATION:
This is the merge step of merge sort algorithm
Two pointers efficiently combine sorted arrays

TIME vs SPACE:
Linear in time (O(m+n))
Uses O(m+n) extra space for merged array
Can be optimized in-place for special cases
*/
