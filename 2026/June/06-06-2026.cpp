// LeetCode 2574. Left and Right Sum Differences
// Daily challenge: 2026-06-06
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n), ans(n);
        for (int i = 1; i < n; i++) left[i] = left[i-1] + nums[i-1];
        for (int i = n-2; i >= 0; i--) right[i] = right[i+1] + nums[i+1];
        for (int i = 0; i < n; i++) ans[i] = abs(left[i] - right[i]);
        return ans;
    }
};
