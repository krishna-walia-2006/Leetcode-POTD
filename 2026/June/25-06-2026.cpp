// LeetCode 3737. Count Subarrays With Majority Element I
// Daily challenge: 2026-06-25
#include <vector>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        long long ans = 0;
        for (int right = 0; right < n; right++) {
            int cnt = 0;
            for (int left = right; left >= 0; left--) {
                if (nums[left] == target) cnt++;
                int len = right - left + 1;
                if (cnt * 2 > len) ans++;
            }
        }
        return (int)ans;
    }
};
