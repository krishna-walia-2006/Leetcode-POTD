// LeetCode 2958. Length of Longest Subarray With at Most K Frequency
// Daily challenge: 2026-08-12
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int left = 0, maxLen = 0;
        for (int right = 0; right < (int)nums.size(); right++) {
            freq[nums[right]]++;
            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
