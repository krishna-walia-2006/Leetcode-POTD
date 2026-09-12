// LeetCode 3867. Sum of GCD of Formed Pairs
// Daily challenge: 2026-07-16
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    long long pairGCDSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixGcd(n);
        long long curMax = 0, curGcd = 0;
        for (int i = 0; i < n; i++) {
            curMax = max(curMax, (long long)nums[i]);
            curGcd = gcd(curGcd, curMax);
            prefixGcd[i] = curGcd;
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        long long sum = 0;
        int l = 0, r = n - 1;
        while (l < r) {
            sum += gcd(prefixGcd[l], prefixGcd[r]);
            l++; r--;
        }
        return sum;
    }
};
