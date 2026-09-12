// LeetCode 1872. Stone Game VIII
// Daily challenge: 2026-08-24
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefix(n, 0);
        prefix[0] = stones[0];
        for (int i = 1; i < n; ++i) prefix[i] = prefix[i - 1] + stones[i];
        int dp = prefix[n - 1];
        for (int i = n - 2; i >= 1; --i) dp = max(dp, prefix[i] - dp);
        return dp;
    }
};
