// LeetCode 2996. Smallest Missing Integer Greater Than Sequential Prefix Sum
// Daily challenge: 2026-08-11
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        long long sum = nums[0];
        int i = 1;
        while (i < n && nums[i] == nums[i - 1] + 1) {
            sum += nums[i];
            i++;
        }
        unordered_set<long long> s(nums.begin(), nums.end());
        long long x = sum;
        while (s.count(x)) x++;
        return (int)x;
    }
};
