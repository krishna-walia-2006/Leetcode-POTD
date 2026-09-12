// LeetCode 2770. Maximum Number of Jumps to Reach the Last Index
// Daily challenge: 2026-05-10
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] != -1 && abs(nums[i]-nums[j]) <= target) dp[i] = max(dp[i], dp[j]+1);
            }
        }
        return dp[n-1];
    }
};
