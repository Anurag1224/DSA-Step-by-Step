// ============================================================================
// PROBLEM 3: Remove Duplicates (Two Pointers In-place)
// ============================================================================
//
// Problem Statement:
// Given a sorted array, remove duplicates in-place.
// Return the length of array with unique elements.
// The first k elements should contain unique values.
//
// Example:
//   Input: [1, 1, 2, 2, 3]
//   Output: 3 (array becomes [1, 2, 3, _, _])
//
// Constraints:
//   1 ≤ n ≤ 10^5
//   Array is sorted in ascending order
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
    
    // Two pointers: j for position to write, i for reading
    int j = 0;
    
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }
    
    int length = j + 1;
    
    cout << length << \"\\n\";
    for (int i = 0; i < length; i++) {
        cout << arr[i];
        if (i < length - 1) cout << \" \";
    }
    cout << \"\\n\";
    
    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Time Complexity: O(n) — single pass
- Space Complexity: O(1) — in-place modification

KEY LEARNING:
1. j = pointer to write unique elements
2. i = pointer to read elements
3. When arr[i] != arr[j], write arr[i] at j+1

DRY RUN ([1, 1, 2, 2, 3]):
j=0 (arr[0]=1)
i=1: arr[1]=1 == arr[0], skip
i=2: arr[2]=2 != arr[0], j=1, arr[1]=2
i=3: arr[3]=2 == arr[1], skip
i=4: arr[4]=3 != arr[1], j=2, arr[2]=3
length = 3
Result: [1, 2, 3] with length 3 ✓

VISUALIZATION:
Original: [1, 1, 2, 2, 3]
         j→
i→
After step 1: [1, 1, 2, 2, 3] (j moved to arr[1])
After step 2: [1, 2, 2, 2, 3] (arr[1] updated to 2)
... continues ...

IN-PLACE MODIFICATION:
We modify the array so first k elements are unique
Rest of array is garbage (but ignored in output)
*/
