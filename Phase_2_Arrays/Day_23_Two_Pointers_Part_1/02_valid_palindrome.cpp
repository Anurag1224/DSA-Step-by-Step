// ============================================================================
// PROBLEM 2: Valid Palindrome (Two Pointers)
// ============================================================================
//
// Problem Statement:
// Given a string, check if it's a palindrome using two pointers.
// Ignore spaces and special characters, case-insensitive.
//
// Example:
//   Input: \"A man, a plan, a canal: Panama\"
//   Output: true
//
//   Input: \"hello\"
//   Output: false
//
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

bool isAlphaNumeric(char c) {
    return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 'a';
    }
    return c;
}

int main() {
    string s;
    getline(cin, s);
    
    // Two pointers approach
    int left = 0, right = s.length() - 1;
    
    while (left < right) {
        // Skip non-alphanumeric from left
        while (left < right && !isAlphaNumeric(s[left])) {
            left++;
        }
        
        // Skip non-alphanumeric from right
        while (left < right && !isAlphaNumeric(s[right])) {
            right--;
        }
        
        // Compare characters (case-insensitive)
        if (toLower(s[left]) != toLower(s[right])) {
            cout << \"false\\n\";
            return 0;
        }
        
        left++;
        right--;
    }
    
    cout << \"true\\n\";
    
    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Time Complexity: O(n) — each character visited once
- Space Complexity: O(1) — no extra space used

KEY LEARNING:
1. Skip non-alphanumeric characters
2. Compare lowercase versions
3. Two pointers efficient for palindrome checking

DRY RUN (\"A man, a plan, a canal: Panama\"):
After removing spaces/punctuation: \"AmanaplanacanalPanama\"
Compare from both ends:
- A vs a → same (case-insensitive)
- m vs m → same
- ... continues ...
All match → true ✓

DRY RUN (\"hello\"):
- h vs o → different → false ✓

LOGIC:
1. Move left pointer right until alphanumeric
2. Move right pointer left until alphanumeric
3. Compare lowercase versions
4. Move inward
5. If any mismatch, return false
*/
