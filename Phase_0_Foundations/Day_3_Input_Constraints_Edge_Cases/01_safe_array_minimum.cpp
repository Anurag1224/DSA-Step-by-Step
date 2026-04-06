#include <bits/stdc++.h>
using namespace std;

// Problem 1: Safe Array Minimum
// Find minimum in array, handle empty array case
// Constraints: N can be 0 to 10^5, values -10^9 to 10^9

int findMinimum(const vector<int>& arr) {
    // Edge case: empty array
    if (arr.empty()) {
        return INT_MIN; // or throw exception, or return error code
    }

    int min_val = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }
    return min_val;
}

int main() {
    // Test cases
    vector<int> empty_arr;
    cout << "Empty array min: " << findMinimum(empty_arr) << endl;

    vector<int> single = {42};
    cout << "Single element min: " << findMinimum(single) << endl;

    vector<int> normal = {3, 1, 4, 1, 5};
    cout << "Normal array min: " << findMinimum(normal) << endl;

    vector<int> negatives = {-5, -1, -10, 0};
    cout << "Negative array min: " << findMinimum(negatives) << endl;

    return 0;
}