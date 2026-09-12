// LeetCode 1674. Minimum Moves to Make Array Complementary
// Daily challenge: 2026-05-13
//

#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> delta(2 * limit + 2, 0);
        for (int i = 0; i < n / 2; i++) {
            int a = nums[i], b = nums[n-1-i];
            int lo = min(a, b), hi = max(a, b);
            delta[2] += 2;
            delta[lo + 1] -= 1;
            delta[a + b] -= 1;
            delta[a + b + 1] += 1;
            delta[hi + limit + 1] += 1;
        }
        int cur = 0, ans = INT_MAX;
        for (int sum = 2; sum <= 2 * limit; sum++) {
            cur += delta[sum];
            ans = min(ans, cur);
        }
        return ans;
    }
};
