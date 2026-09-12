// LeetCode 1140. Stone Game II
// Daily challenge: 2026-08-09
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffixSum(n, 0);
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; --i) suffixSum[i] = suffixSum[i + 1] + piles[i];
        vector<vector<int>> memo(n, vector<int>(n + 1, 0));
        return helper(piles, suffixSum, 0, 1, memo);
    }
private:
    int helper(vector<int>& piles, vector<int>& suffixSum, int i, int M, vector<vector<int>>& memo) {
        if (i + 2 * M >= (int)piles.size()) return suffixSum[i];
        if (memo[i][M] != 0) return memo[i][M];
        int res = 0;
        for (int x = 1; x <= 2 * M; ++x) {
            res = max(res, suffixSum[i] - helper(piles, suffixSum, i + x, max(M, x), memo));
        }
        return memo[i][M] = res;
    }
};
