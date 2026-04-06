#include <bits/stdc++.h>
using namespace std;

// Problem 5: Negative Number Handler
// Process numbers that could be negative
// Constraints: handle negative, zero, positive

int processNumber(int num) {
    // Edge cases for negative numbers
    if (num < 0) {
        return -num; // absolute value
    } else if (num == 0) {
        return 0; // zero case
    } else {
        return num * 2; // positive case
    }
}

bool isNegative(int num) {
    return num < 0;
}

int main() {
    // Test cases
    vector<int> test_nums = {-5, -1, 0, 1, 5, 100};

    for (int num : test_nums) {
        cout << "Number: " << num
             << ", Is negative: " << isNegative(num)
             << ", Processed: " << processNumber(num) << endl;
    }

    // Edge cases
    cout << "INT_MIN: " << INT_MIN
         << ", Is negative: " << isNegative(INT_MIN) << endl;

    cout << "INT_MAX: " << INT_MAX
         << ", Is negative: " << isNegative(INT_MAX) << endl;

    return 0;
}