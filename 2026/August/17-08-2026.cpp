// LeetCode 1563. Stone Game V
// Daily challenge: 2026-08-17
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + stoneValue[i];
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return dfs(stoneValue, prefix, 0, n - 1, memo);
    }
private:
    int dfs(vector<int>& stoneValue, vector<int>& prefix, int left, int right, vector<vector<int>>& memo) {
        if (left == right) return 0;
        if (memo[left][right] != -1) return memo[left][right];
        int max_score = 0;
        for (int i = left; i < right; i++) {
            int left_sum = prefix[i + 1] - prefix[left];
            int right_sum = prefix[right + 1] - prefix[i + 1];
            if (left_sum < right_sum) {
                max_score = max(max_score, left_sum + dfs(stoneValue, prefix, left, i, memo));
            } else if (left_sum > right_sum) {
                max_score = max(max_score, right_sum + dfs(stoneValue, prefix, i + 1, right, memo));
            } else {
                max_score = max(max_score, left_sum + max(dfs(stoneValue, prefix, left, i, memo),
                                                            dfs(stoneValue, prefix, i + 1, right, memo)));
            }
        }
        return memo[left][right] = max_score;
    }
};
