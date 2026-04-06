#include <bits/stdc++.h>
using namespace std;

// Problem 3: Safe Division
// Perform division with zero check
// Constraints: integers, handle division by zero

double safeDivide(int numerator, int denominator) {
    // Edge case: division by zero
    if (denominator == 0) {
        throw runtime_error("Division by zero");
        // or return numeric_limits<double>::quiet_NaN();
        // or return 0.0; with error flag
    }

    return static_cast<double>(numerator) / denominator;
}

int main() {
    try {
        // Test cases
        cout << "10/2 = " << safeDivide(10, 2) << endl;
        cout << "5/0 = " << safeDivide(5, 0) << endl; // This will throw
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    // Edge cases
    try {
        cout << "0/5 = " << safeDivide(0, 5) << endl;
        cout << "-10/2 = " << safeDivide(-10, 2) << endl;
        cout << "10/-2 = " << safeDivide(10, -2) << endl;
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}