// ============================================================================
// PROBLEM 3: Insertion Sort - Build Sorted Array Incrementally
// ============================================================================
//
// Problem Statement:
// Implement insertion sort. Most practical O(n²) sorting algorithm.
//
// How it works:
// - Consider first element as sorted
// - For each new element, find correct position in sorted part
// - Insert element, shifting others right
// - Repeat until all elements processed
//
// Example:
//   Input: [64, 34, 25, 12, 22]
//   Output: [12, 22, 25, 34, 64]
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
    
    // INSERTION SORT
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Shift elements greater than key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        // Insert key at correct position
        arr[j + 1] = key;
    }
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    
    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Best Case: O(n) — array already sorted, no shifts
- Average Case: O(n²)
- Worst Case: O(n²) — array reverse sorted
- Space Complexity: O(1) — in-place
- Stability: YES — equal elements maintain order

WHY IT'S BEST O(n²):
1. Performs well on nearly sorted data
2. Online algorithm — can sort data as it arrives
3. Adaptive — O(n) on sorted, O(n²) on random
4. Stable sorting
5. Used in real systems (hybrid sorts, final pass)

DRY RUN ([3, 1, 4, 1, 5]):
i=1: key=1, shift 3 right → [1, 3, 4, 1, 5]
i=2: key=4, no shift → [1, 3, 4, 1, 5]
i=3: key=1, shift 4,3,1 right → [1, 1, 3, 4, 5]
i=4: key=5, no shift → [1, 1, 3, 4, 5]
Output: [1, 1, 3, 4, 5]

KEY ADVANTAGES:
1. Stable — maintains relative order of equal elements
2. Adaptive — fast on nearly sorted data
3. Online — can sort stream of data
4. Cache-friendly — sequential memory access
5. Lower overhead than merge/quick sort

USE CASES:
- Small arrays (used as final pass in hybrid sorts)
- Nearly sorted data
- Online sorting scenarios
- When stability is critical
- When simplicity is preferred (embedded systems)

REAL-WORLD EXAMPLE:
Tim Sort (Python's default) uses insertion sort for small arrays
before merging results. Why? It's fast on small, potentially
partially-sorted data.

VARIATION - BINARY INSERTION SORT:
Use binary search to find insertion position: O(n log n)
comparisons, but still O(n²) shifts. Better for large datasets.
*/
