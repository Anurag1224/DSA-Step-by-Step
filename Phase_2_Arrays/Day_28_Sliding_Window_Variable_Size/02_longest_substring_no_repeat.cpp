/*
PROBLEM: Longest Substring Without Repeating Characters
Find length of longest substring without repeating chars.

Example: s = "abcabcbb" -> 3 ("abc")

KEY INSIGHT:
- Track last seen index of each character
- Move left pointer when duplicate found
- Update maximum length
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charIndex;  // Char -> last seen index
    int maxLen = 0;
    int left = 0;
    
    for (int right = 0; right < s.size(); right++) {
        char c = s[right];
        
        // If character seen and in current window
        if (charIndex.count(c) && charIndex[c] >= left) {
            left = charIndex[c] + 1;
        }
        
        // Update max length
        maxLen = max(maxLen, right - left + 1);
        
        // Update last seen index
        charIndex[c] = right;
    }
    
    return maxLen;
}

int main() {
    // Test case 1
    cout << "\"abcabcbb\": " << lengthOfLongestSubstring("abcabcbb") << " (expected 3)\n";
    
    // Test case 2
    cout << "\"bbbbb\": " << lengthOfLongestSubstring("bbbbb") << " (expected 1)\n";
    
    // Test case 3
    cout << "\"pwwkew\": " << lengthOfLongestSubstring("pwwkew") << " (expected 3)\n";
    
    // Test case 4
    cout << "\"au\": " << lengthOfLongestSubstring("au") << " (expected 2)\n";
    
    return 0;
}

/*
TIME: O(n)
SPACE: O(min(n, m)) where m is charset size

DRY RUN:
s = "abcabcbb"
left=0, maxLen=0, charIndex={}

right=0, c='a': maxLen=1, charIndex={a:0}
right=1, c='b': maxLen=2, charIndex={a:0, b:1}
right=2, c='c': maxLen=3, charIndex={a:0, b:1, c:2}
right=3, c='a': a at 0 >= 0, left=1, maxLen=3
right=4, c='b': b at 1 >= 1, left=2, maxLen=3
right=5, c='c': c at 2 >= 2, left=3, maxLen=3
right=6, c='b': maxLen=3
right=7, c='b': b at 6 >= 3, left=7, maxLen=3

Result: 3 ✓
*/
