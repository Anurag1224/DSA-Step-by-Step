#include <bits/stdc++.h>
using namespace std;

// Problem 4: Boundary Sum
// Sum array elements, handle overflow potential
// Constraints: N=1 to 10^5, values -10^9 to 10^9

long long safeSum(const vector<int>& arr) {
    // Edge case: empty array
    if (arr.empty()) {
        return 0;
    }

    long long sum = 0;
    for (int num : arr) {
        // Check for overflow before adding
        if (sum > LLONG_MAX - num) {
            throw overflow_error("Sum overflow");
        }
        if (sum < LLONG_MIN - num) {
            throw underflow_error("Sum underflow");
        }
        sum += num;
    }
    return sum;
}

int main() {
    // Test cases
    vector<int> normal = {1, 2, 3, 4, 5};
    cout << "Normal sum: " << safeSum(normal) << endl;

    vector<int> negatives = {-1, -2, -3};
    cout << "Negative sum: " << safeSum(negatives) << endl;

    vector<int> empty_arr;
    cout << "Empty sum: " << safeSum(empty_arr) << endl;

    // Edge case: large numbers (but within long long range)
    vector<int> large = {1000000000, 1000000000};
    cout << "Large sum: " << safeSum(large) << endl;

    return 0;
}