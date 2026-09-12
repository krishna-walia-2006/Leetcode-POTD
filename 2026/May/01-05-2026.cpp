// LeetCode 396. Rotate Function
// Daily challenge: 2026-05-01
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long sum = 0, F = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) { sum += nums[i]; F += (long long)i * nums[i]; }
        long long maxF = F;
        for (int i = n - 1; i >= 1; i--) {
            F = F + sum - (long long)n * nums[i];
            maxF = max(maxF, F);
        }
        return (int)maxF;
    }
};
