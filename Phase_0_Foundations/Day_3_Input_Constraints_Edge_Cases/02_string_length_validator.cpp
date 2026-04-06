#include <bits/stdc++.h>
using namespace std;

// Problem 2: String Length Validator
// Check if string meets length constraints
// Constraints: string length 0 to 10^5

bool isValidLength(const string& str, int min_len, int max_len) {
    // Edge cases
    if (min_len < 0 || max_len < min_len) {
        return false; // invalid constraints
    }

    size_t len = str.length();
    return len >= min_len && len <= max_len;
}

int main() {
    // Test cases
    string empty = "";
    cout << "Empty string (1-10): " << isValidLength(empty, 1, 10) << endl;

    string short_str = "hi";
    cout << "Short string (1-10): " << isValidLength(short_str, 1, 10) << endl;

    string long_str = string(100, 'a');
    cout << "Long string (1-10): " << isValidLength(long_str, 1, 10) << endl;

    // Edge case: min_len = 0
    cout << "Empty string (0-10): " << isValidLength(empty, 0, 10) << endl;

    // Edge case: max_len = 0
    cout << "Empty string (0-0): " << isValidLength(empty, 0, 0) << endl;

    return 0;
}