/*
PROBLEM: Permutation in String
Check if s2 contains a permutation of s1.

Example: s1 = "ab", s2 = "eidbaooo" -> true ("ba")

KEY INSIGHT:
- Use sliding window of size len(s1)
- Compare character frequency in window with s1
- Slide window and update frequency
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) return false;
    
    vector<int> s1Count(26, 0), windowCount(26, 0);
    
    // Count characters in s1
    for (char c : s1) {
        s1Count[c - 'a']++;
    }
    
    int windowSize = s1.size();
    
    for (int i = 0; i < s2.size(); i++) {
        // Add character to window
        windowCount[s2[i] - 'a']++;
        
        // Remove character if window exceeds size
        if (i >= windowSize) {
            windowCount[s2[i - windowSize] - 'a']--;
        }
        
        // Check if window matches s1
        if (i >= windowSize - 1 && windowCount == s1Count) {
            return true;
        }
    }
    
    return false;
}

int main() {
    // Test case 1
    cout << "s1=\"ab\", s2=\"eidbaooo\": " << (checkInclusion("ab", "eidbaooo") ? "true" : "false") << " (expected true)\n";
    
    // Test case 2
    cout << "s1=\"ab\", s2=\"ab\": " << (checkInclusion("ab", "ab") ? "true" : "false") << " (expected true)\n";
    
    // Test case 3
    cout << "s1=\"ab\", s2=\"a\": " << (checkInclusion("ab", "a") ? "true" : "false") << " (expected false)\n";
    
    return 0;
}

/*
TIME: O(n) where n is length of s2
SPACE: O(1) - fixed size arrays

DRY RUN:
s1 = "ab", s2 = "eidbaooo"
s1Count = [0,...,1(a),1(b),0,...]
windowSize = 2

i=0: window="e", windowCount[4]=1
i=1: window="ei", 
i=2: window="id", 
... (continues, comparing arrays)
i=5: window="ao", windowCount[0]=1, windowCount[14]=1
     Compare with s1Count: match? No
i=6: window="oo", 
i=7: window="oo",
... not matching

Actually, "ba" at position 3-4 matches!
i=3: window="db", not matching
i=4: window="ba", matches s1Count ✓

KEY: Vector comparison is efficient for small alphabets
*/
