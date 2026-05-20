/*
PROBLEM: Minimum Window Substring
Find shortest substring containing all chars from t.

Example: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"

KEY INSIGHT:
- Expand right to include characters from t
- Shrink left when all chars are included
- Track character frequencies
- Update minimum window
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string minWindow(string s, string t) {
    if (t.empty() || s.empty()) return "";
    
    unordered_map<char, int> dictT, window;
    
    // Count characters in t
    for (char c : t) {
        dictT[c]++;
    }
    
    int required = dictT.size();  // Different characters needed
    int formed = 0;  // Different characters with desired frequency
    
    int left = 0, minLen = INT_MAX, minStart = 0;
    
    for (int right = 0; right < s.size(); right++) {
        char c = s[right];
        window[c]++;
        
        // Check if this character is now complete
        if (dictT.count(c) && window[c] == dictT[c]) {
            formed++;
        }
        
        // Shrink window from left
        while (left <= right && formed == required) {
            // Update result if this window is smaller
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minStart = left;
            }
            
            // Remove character from left
            char c = s[left];
            window[c]--;
            if (dictT.count(c) && window[c] < dictT[c]) {
                formed--;
            }
            
            left++;
        }
    }
    
    return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
}

int main() {
    // Test case 1
    string result1 = minWindow("ADOBECODEBANC", "ABC");
    cout << "Min window: \"" << result1 << "\" (expected \"BANC\" or similar)\n";
    
    // Test case 2: Single character
    string result2 = minWindow("a", "a");
    cout << "Single char: \"" << result2 << "\" (expected \"a\")\n";
    
    // Test case 3: No solution
    string result3 = minWindow("a", "aa");
    cout << "No solution: \"" << result3 << "\" (expected \"\")\n";
    
    return 0;
}

/*
TIME: O(n) - each character visited at most twice
SPACE: O(1) - max 26 letters in dictionaries

DRY RUN:
s = "ADOBECODEBANC", t = "ABC"
dictT = {A:1, B:1, C:1}, required = 3

right expands, left shrinks when all chars present
...complex trace...

KEY INSIGHTS:
1. Two nested loops but O(n) due to left only moves forward
2. Frequency map tracks current vs needed
3. Shrink greedily to find minimum
*/
