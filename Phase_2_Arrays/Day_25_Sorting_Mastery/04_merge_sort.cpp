// ============================================================================
// PROBLEM 4: Merge Sort - Divide and Conquer Excellence
// ============================================================================
//
// Problem Statement:
// Implement merge sort. O(n log n) guaranteed, stable, divide-and-conquer.
//
// How it works:
// - Divide: Split array into halves recursively
// - Conquer: Sort each half
// - Combine: Merge sorted halves back together
//
// Example:
//   Input: [64, 34, 25, 12, 22, 11, 90]
//   Output: [11, 12, 22, 25, 34, 64, 90]
//
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    // Create temporary arrays for left and right halves
    vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);
    
    int i = 0, j = 0, k = left;
    
    // Merge: Compare and place smaller elements
    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }
    
    // Copy remaining elements
    while (i < leftArr.size()) {
        arr[k++] = leftArr[i++];
    }
    while (j < rightArr.size()) {
        arr[k++] = rightArr[j++];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        // Divide
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        // Combine
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    mergeSort(arr, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    
    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Best Case: O(n log n)
- Average Case: O(n log n)
- Worst Case: O(n log n) — GUARANTEED
- Space Complexity: O(n) — not in-place (temp arrays)
- Stability: YES — equal elements maintain order

WHY O(n log n):
- Tree depth: log n (divide array in half each level)
- Work per level: O(n) (merge all elements)
- Total: O(n) × O(log n) = O(n log n)

ADVANTAGES:
1. Guaranteed O(n log n) — predictable performance
2. Stable — maintains order of equal elements
3. Predictable memory usage — no bad worst cases
4. Parallelizable — can sort left/right in parallel

DISADVANTAGES:
1. Requires O(n) extra space
2. Higher overhead than quick sort in practice
3. Slower on small arrays

DRY RUN ([38, 27, 43, 3]):
Level 1: [38, 27] | [43, 3]
  Merge [38,27] → [27,38]
  Merge [43,3] → [3,43]
Level 2: [27, 38] | [3, 43]
  Merge → [3, 27, 38, 43]
Output: [3, 27, 38, 43]

STABILITY:
Equal elements maintain relative order:
Input: [(3,'a'), (1,'b'), (3,'c')]
Output: [(1,'b'), (3,'a'), (3,'c')] — first 3 is 'a'

USE CASES:
1. When guaranteed O(n log n) is required
2. When stability is critical
3. Linked lists (no random access needed)
4. External sorting (disk I/O friendly)
5. Parallel processing
6. Production databases (PostgreSQL uses variant)

OPTIMIZATION - EXTERNAL MERGE SORT:
For files > memory: Read chunks, sort, write back, merge.
This is how databases sort massive datasets!
*/
