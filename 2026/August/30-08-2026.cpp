// LeetCode 2091. Removing Minimum and Maximum From Array
// Daily challenge: 2026-08-30
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int min_idx = min_element(nums.begin(), nums.end()) - nums.begin();
        int max_idx = max_element(nums.begin(), nums.end()) - nums.begin();
        int left = min(min_idx, max_idx);
        int right = max(min_idx, max_idx);
        return min({right + 1, n - left, (left + 1) + (n - right)});
    }
};
