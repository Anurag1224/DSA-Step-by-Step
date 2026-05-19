// ============================================================================
// PROBLEM 1: Bubble Sort - Understanding the Basics
// ============================================================================
//
// Problem Statement:
// Implement bubble sort and understand why it's rarely used in production.
//
// How it works:
// - Compare adjacent elements
// - Swap if they're in wrong order
// - Repeat until array is sorted
// - After each pass, largest element "bubbles" to end
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
    
    // BUBBLE SORT
    for (int i = 0; i < n; i++) {
        bool swapped = false;
        
        // Each pass bubbles largest unsorted element to right
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        
        // Optimization: if no swaps, array already sorted
        if (!swapped) break;
    }
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    
    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Best Case: O(n) — array already sorted, early break
- Average Case: O(n²) — typical case
- Worst Case: O(n²) — array sorted in reverse
- Space Complexity: O(1) — in-place sorting
- Stability: YES — equal elements maintain relative order

KEY INSIGHTS:
1. Very inefficient for large arrays
2. Optimization with swapped flag helps best case
3. Each pass guarantees one element in final position
4. Easy to understand but rarely used in practice

DRY RUN ([3, 1, 4, 1, 5]):
Pass 1: [1, 3, 1, 4, 5] — 5 bubbled to end
Pass 2: [1, 1, 3, 4, 5] — 4 bubbled to position
Pass 3: [1, 1, 3, 4, 5] — no swaps, done!
Output: [1, 1, 3, 4, 5]

WHEN TO USE:
- Educational purposes
- Very small arrays (< 10 elements)
- Nearly sorted data (with early termination)
- NEVER in production code

VISUALIZATION:
Pass 1: 3|1 4|1 5 → 1|3 4|1 5 → 1|3 4|1 5 → 1|3 1|4 5 → 1|3 1|4 5
        [1,3,4,1,5] → [1,3,1,4,5] → [1,3,1,4,5] → [1,3,1,4,5] → Bubble! 5 at end

COMPARISON WITH OTHER O(n²):
- Bubble Sort: Many passes, adjacent swaps
- Selection Sort: Find minimum each pass
- Insertion Sort: Build sorted portion incrementally
*/
