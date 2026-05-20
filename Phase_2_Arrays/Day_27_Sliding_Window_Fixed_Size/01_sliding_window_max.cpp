/*
PROBLEM: Sliding Window Maximum
Find maximum in each window of size k.

Example: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,-1,3,5,6,7]

KEY INSIGHT:
- Use deque to store indices
- Keep deque in decreasing order
- Remove indices outside window
*/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> dq;  // Store indices, not values
    
    for (int i = 0; i < nums.size(); i++) {
        // Remove indices outside current window
        if (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }
        
        // Remove elements smaller than current from back
        // (they can never be max)
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        
        // Add current index
        dq.push_back(i);
        
        // First window complete
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    
    return result;
}

int main() {
    // Test case 1
    vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> result1 = maxSlidingWindow(nums1, 3);
    cout << "Window max k=3: ";
    for (int x : result1) cout << x << " ";
    cout << "(expected 3 3 -1 3 5 6 7)\n";
    
    // Test case 2: k = 1
    vector<int> nums2 = {1, 3, -1};
    vector<int> result2 = maxSlidingWindow(nums2, 1);
    cout << "Window max k=1: ";
    for (int x : result2) cout << x << " ";
    cout << "(expected 1 3 -1)\n";
    
    return 0;
}

/*
TIME: O(n) - each element enters and leaves deque once
SPACE: O(k) - deque size at most k

DRY RUN:
nums = [1, 3, -1, -3, 5, 3, 6, 7], k = 3

i=0: dq=[0]
i=1: nums[1]=3 > nums[0]=1, pop 0, dq=[1]
i=2: nums[2]=-1, dq=[1,2], i>=k-1 -> result=[3]
i=3: remove 0 (outside), nums[3]=-3, dq=[1,2,3], result=[3,3]
i=4: remove 1, nums[4]=5 > all, dq=[4], result=[3,3,-1]
...

KEY: Deque maintains decreasing order of values
*/
