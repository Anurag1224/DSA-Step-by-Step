#include <bits/stdc++.h>
using namespace std;

/*
Problem: Find Single Number (XOR Trick)
Given array where all elements appear twice except one, find the unique element.

Time: O(n)
Space: O(1)

KEY CONCEPT:
- XOR is associative and commutative
- a ^ a = 0 (XOR with itself cancels)
- a ^ 0 = a (XOR with zero is identity)
- XOR all elements: duplicates cancel, unique remains
*/

class SingleNumberFinder {
public:
    // Method 1: Using XOR (most efficient)
    int findSingle_xor(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }

    // Method 2: Using hash map (educational)
    int findSingle_hashmap(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        for (auto& pair : freq) {
            if (pair.second == 1) {
                return pair.first;
            }
        }
        return -1; // Should not reach here
    }

    // Method 3: Using sorting (educational)
    int findSingle_sort(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (size_t i = 0; i < nums.size(); i += 2) {
            if (i == nums.size() - 1 || nums[i] != nums[i + 1]) {
                return nums[i];
            }
        }
        return -1; // Should not reach here
    }

    // Advanced: Find two unique numbers (all others appear twice)
    pair<int, int> findTwoUnique(vector<int>& nums) {
        // Step 1: XOR all elements
        int xor_all = 0;
        for (int num : nums) {
            xor_all ^= num;
        }

        // Step 2: Find rightmost set bit (where the two numbers differ)
        int rightmost_set_bit = xor_all & -xor_all;

        // Step 3: Divide numbers into two groups and XOR each group
        int num1 = 0, num2 = 0;
        for (int num : nums) {
            if (num & rightmost_set_bit) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }

        return {num1, num2};
    }

    // Advanced: Find element that appears odd number of times
    int findOddOccurrence(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;  // Even occurrences cancel, odd remains
        }
        return result;
    }

    // XOR properties demonstration
    void demonstrateXorProperties() {
        cout << "XOR Properties:" << endl;
        cout << "a ^ a = 0: " << (5 ^ 5) << endl;
        cout << "a ^ 0 = a: " << (5 ^ 0) << endl;
        cout << "Associative: (a ^ b) ^ c = a ^ (b ^ c)" << endl;
        cout << "Commutative: a ^ b = b ^ a" << endl;
        cout << "Self-inverse: (a ^ b) ^ b = a" << endl;
    }
};

/*
KEY LEARNINGS:
1. XOR cancels duplicates: a ^ a = 0
2. XOR with 0 is identity: a ^ 0 = a
3. Order doesn't matter: associative and commutative
4. Can find single element in O(n) time, O(1) space
5. Extends to finding elements with odd occurrences

EXAMPLES:
Input: [2, 2, 1] → 1 (only appears once)
Input: [4, 1, 2, 1, 2] → 4 (only appears once)

WHY IT WORKS:
2 ^ 2 ^ 1 = (2 ^ 2) ^ 1 = 0 ^ 1 = 1

REAL-WORLD APPLICATIONS:
- Finding duplicate in large dataset
- Error detection (parity bits)
- Cryptography (stream ciphers)
- Memory-efficient duplicate detection
*/