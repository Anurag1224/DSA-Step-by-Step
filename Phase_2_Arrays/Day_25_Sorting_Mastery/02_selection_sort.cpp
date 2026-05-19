// ============================================================================
// PROBLEM 2: Selection Sort - Find and Place
// ============================================================================
//
// Problem Statement:
// Implement selection sort. For each position, find minimum and place it.
//
// How it works:
// - Find minimum element in unsorted portion
// - Place it at the beginning of unsorted portion
// - Move boundary between sorted and unsorted
// - Repeat until entire array sorted
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
    
    // SELECTION SORT
    for (int i = 0; i < n - 1; i++) {
        // Find minimum in unsorted portion [i, n-1]
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        
        // Place minimum at position i
        if (minIdx != i) {
            swap(arr[i], arr[minIdx]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    
    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Best Case: O(n²) — still scans for minimum
- Average Case: O(n²)
- Worst Case: O(n²)
- Space Complexity: O(1) — in-place
- Stability: NO — swaps can reverse equal elements order

KEY INSIGHTS:
1. Always O(n²) because we always find minimum
2. Number of swaps is minimal (at most n-1)
3. Good for memory-constrained systems (few writes)
4. Not stable — might reverse equal elements

DRY RUN ([64, 34, 25, 12, 22]):
i=0: min at index 3 (12), swap: [12, 34, 25, 64, 22]
i=1: min at index 4 (22), swap: [12, 22, 25, 64, 34]
i=2: min at index 2 (25), no swap: [12, 22, 25, 64, 34]
i=3: min at index 4 (34), swap: [12, 22, 25, 34, 64]
Output: [12, 22, 25, 34, 64]

WHY NOT STABLE:
[3, 1, 3, 2] → First 3 swapped with last element
→ Relative order of equal 3's reversed

COMPARISON: O(n²) Sorts
- Bubble: Many comparisons AND swaps
- Selection: Many comparisons, FEW swaps (best for limited writes)
- Insertion: Better in practice, stable

WHEN TO USE:
- When number of writes must be minimized
- Very small arrays
- Cache locality not important
- RARELY in modern systems
*/
