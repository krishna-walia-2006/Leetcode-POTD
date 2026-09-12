// LeetCode 3471. Find the Largest Almost Missing Integer
// Daily challenge: 2026-08-18
//

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == n) return *max_element(nums.begin(), nums.end());

        unordered_map<int,int> freq;
        for (int x : nums) freq[x]++;

        if (k == 1) {
            int ans = -1;
            for (int x : nums) if (freq[x] == 1) ans = max(ans, x);
            return ans;
        }

        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (i <= k - 2 || i >= n - k + 1) {
                if (freq[nums[i]] == 1) ans = max(ans, nums[i]);
            }
        }
        return ans;
    }
};
