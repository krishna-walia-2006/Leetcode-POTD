// LeetCode 3739. Count Subarrays With Majority Element II
// Daily challenge: 2026-06-26
//

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + (nums[i] == target ? 1 : -1);

        vector<long long> sortedVals = prefix;
        sort(sortedVals.begin(), sortedVals.end());
        sortedVals.erase(unique(sortedVals.begin(), sortedVals.end()), sortedVals.end());
        int m = sortedVals.size();

        vector<int> bit(m + 1, 0);
        auto update = [&](int i) { for (; i <= m; i += i & (-i)) bit[i]++; };
        auto query = [&](int i) { int s = 0; for (; i > 0; i -= i & (-i)) s += bit[i]; return s; };

        long long ans = 0;
        for (int j = 0; j <= n; j++) {
            int idx = lower_bound(sortedVals.begin(), sortedVals.end(), prefix[j]) - sortedVals.begin();
            ans += query(idx);
            update(idx + 1);
        }
        return ans;
    }
};
