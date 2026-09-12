// LeetCode 1979. Find Greatest Common Divisor of Array
// Daily challenge: 2026-07-18
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        return gcd(mn, mx);
    }
};
