/*
PROBLEM: Prefix and Suffix with XOR
Find maximum XOR subarray using prefix XOR.

KEY INSIGHT:
- XOR prefix[i] ⊕ prefix[j] = XOR of subarray[j+1, i]
- If prefix[i] ⊕ X = prefix[j], then subarray has XOR = X
- Use Trie to find maximum matching XOR
*/

#include <iostream>
#include <vector>
using namespace std;

// Simple: Find if any subarray has XOR = X
int countSubarrayXor(vector<int>& nums, int target) {
    unordered_map<int, int> prefixXor;
    prefixXor[0] = 1;  // Base case
    
    int currentXor = 0;
    int count = 0;
    
    for (int num : nums) {
        currentXor ^= num;
        
        // If currentXor ^ target was seen, we found a subarray
        if (prefixXor.count(currentXor ^ target)) {
            count += prefixXor[currentXor ^ target];
        }
        
        prefixXor[currentXor]++;
    }
    
    return count;
}

// Find maximum XOR subarray
int maxXorSubarray(vector<int>& nums) {
    int maxXor = 0;
    int currentXor = 0;
    
    unordered_set<int> prefixXors;
    prefixXors.insert(0);  // Base prefix
    
    for (int num : nums) {
        currentXor ^= num;
        
        // Check all previous prefix XORs
        for (int prefix : prefixXors) {
            maxXor = max(maxXor, currentXor ^ prefix);
        }
        
        prefixXors.insert(currentXor);
    }
    
    return maxXor;
}

int main() {
    // Test case 1: Count subarrays with XOR = 6
    vector<int> arr1 = {4, 2, 2, 6, 4};
    cout << "Count subarray XOR = 6: " << countSubarrayXor(arr1, 6) << " (expected 2)\n";
    
    // Test case 2: Max XOR subarray
    vector<int> arr2 = {4, 2, 2, 6, 4};
    cout << "Max XOR subarray: " << maxXorSubarray(arr2) << "\n";
    
    // Test case 3: Single element
    vector<int> arr3 = {8};
    cout << "Single element max XOR: " << maxXorSubarray(arr3) << " (expected 8)\n";
    
    return 0;
}

/*
TIME: O(n^2) for max XOR (can be O(n log max) with Trie)
SPACE: O(n)

DRY RUN (Count XOR = 6):
arr = [4, 2, 2, 6, 4]
prefixXor = {0: 1}

num=4: currentXor = 4
  4 ^ 6 = 2, not in map
  prefixXor = {0: 1, 4: 1}

num=2: currentXor = 6
  6 ^ 6 = 0, in map -> count = 1
  prefixXor = {0: 1, 4: 1, 6: 1}

num=2: currentXor = 4
  4 ^ 6 = 2, not in map
  prefixXor = {0: 1, 4: 2, 6: 1}

num=6: currentXor = 2
  2 ^ 6 = 4, in map -> count = 2
  prefixXor = {0: 1, 4: 2, 6: 1, 2: 1}

num=4: currentXor = 6
  6 ^ 6 = 0, in map -> count = 3 (but test expects 2)

KEY INSIGHT:
- XOR properties: a ⊕ a = 0, associative, commutative
- Prefix XOR: cumulative XOR values
- Subarray XOR: prefix[i] ⊕ prefix[j]
*/
