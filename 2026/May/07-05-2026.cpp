// LeetCode 3660. Jump Game IX
// Daily challenge: 2026-05-07

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<pair<int,int>> stk; // {start, maxVal}
        for (int i = 0; i < n; i++) {
            int start = i, curMax = nums[i];
            while (!stk.empty() && stk.back().second > nums[i]) {
                start = stk.back().first;
                curMax = max(curMax, stk.back().second);
                stk.pop_back();
            }
            stk.push_back({start, curMax});
        }
        int idx = n - 1;
        for (int k = (int)stk.size() - 1; k >= 0; k--) {
            int start = stk[k].first, maxVal = stk[k].second;
            for (int i = idx; i >= start; i--) ans[i] = maxVal;
            idx = start - 1;
        }
        return ans;
    }
};
