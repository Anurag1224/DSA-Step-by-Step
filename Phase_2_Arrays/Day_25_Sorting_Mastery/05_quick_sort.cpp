// ============================================================================
// PROBLEM 5: Quick Sort - Fast Average Case Performance
// ============================================================================
//
// Problem Statement:
// Implement quick sort. O(n log n) average, O(n²) worst, in-place.
//
// How it works:
// - Choose pivot element
// - Partition: elements < pivot go left, > pivot go right
// - Recursively sort left and right partitions
// - No merging needed (in-place)
//
// Example:
//   Input: [64, 34, 25, 12, 22, 11, 90]
//   Output: [11, 12, 22, 25, 34, 64, 90]
//
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    // Choose last element as pivot
    int pivot = arr[high];
    int i = low - 1;  // Index of smaller element
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    // Place pivot in final position
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition and get pivot position
        int pi = partition(arr, low, high);
        
        // Sort left of pivot
        quickSort(arr, low, pi - 1);
        
        // Sort right of pivot
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    quickSort(arr, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    
    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Best Case: O(n log n) — pivot always at middle
- Average Case: O(n log n) — typical random arrays
- Worst Case: O(n²) — pivot always at ends (sorted array!)
- Space Complexity: O(log n) — recursion stack
- Stability: NO — partition destroys order

WHY FASTER IN PRACTICE:
1. In-place: No extra arrays needed
2. Cache-friendly: Sequential swaps
3. Small recursion overhead
4. Good pivot selection avoids worst case
5. Used in std::sort (hybrid approach)

DRY RUN ([3, 1, 4, 1, 5, 9]):
pivot = 9, partition: [3, 1, 4, 1, 5] | [9]
  i pointer finds first >= 9, none before
  [3, 1, 4, 1, 5, 9] (9 at correct position)
Left: [3, 1, 4, 1, 5]
  pivot = 5, partition: [3, 1, 4, 1] | [5] | [9]
  Continue recursively...

PARTITION STEP VISUAL:
Initial: [3, 7, 8, 5, 2, 1, 9]
pivot = 9
i points to elements < 9: [3, 7, 8, 5, 2, 1] | [9]
No swaps needed, 9 already last
Result: [3, 7, 8, 5, 2, 1, 9]

WORST CASE EXAMPLE:
Array: [1, 2, 3, 4, 5] (sorted!)
- Pick 5 as pivot: 4 comparisons, 1 element sorted
- Left: [1, 2, 3, 4]
- Pick 4 as pivot: 3 comparisons, 1 element sorted
- Continue... O(n + (n-1) + (n-2) + ... + 1) = O(n²)

OPTIMIZATION - 3-WAY PARTITION (Bentley-McIlroy):
For arrays with duplicates:
- Elements < pivot (left)
- Elements = pivot (middle)
- Elements > pivot (right)
Reduces O(n²) cases when many duplicates!

PIVOT SELECTION STRATEGIES:
1. Last element (simple, but bad on sorted data)
2. First element (also bad on sorted data)
3. Middle element (better, but not perfect)
4. Random element (good average, hard to exploit)
5. Median-of-three (good practice, balances tree)

USE CASES:
1. General-purpose sorting (fastest average)
2. When stability not required
3. When space is limited (in-place)
4. Nearly all library implementations use it
5. Best for random/unsorted data

NOT GOOD FOR:
1. Real-time systems (need guaranteed time)
2. Mostly sorted data (tends to O(n²))
3. When stability is critical
4. With many duplicates (unless 3-way variant)
*/
