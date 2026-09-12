// LeetCode 628. Maximum Product of Three Numbers
// Daily challenge: 2026-07-26
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return max(nums[n-1]*nums[n-2]*nums[n-3], nums[0]*nums[1]*nums[n-1]);
    }
};
