// LeetCode 3691. Maximum Total Subarray Value II
// Daily challenge: 2026-06-10
//

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> values;
        for (int i = 0; i < n; i++) {
            int mx = nums[i], mn = nums[i];
            for (int j = i; j < n; j++) {
                mx = max(mx, nums[j]);
                mn = min(mn, nums[j]);
                values.push_back(mx - mn);
            }
        }
        sort(values.rbegin(), values.rend());
        long long ans = 0;
        for (int i = 0; i < k && i < (int)values.size(); i++) ans += values[i];
        return ans;
    }
};
