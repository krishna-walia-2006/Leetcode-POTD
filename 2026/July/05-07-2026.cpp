// LeetCode 1301. Number of Paths with Max Score
// Daily challenge: 2026-07-05
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const long long MOD = 1e9 + 7;
        vector<vector<long long>> dpSum(n, vector<long long>(n, -1));
        vector<vector<long long>> dpCount(n, vector<long long>(n, 0));
        dpSum[n-1][n-1] = 0;
        dpCount[n-1][n-1] = 1;

        int di[3] = {1, 0, 1};
        int dj[3] = {0, 1, 1};
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == n-1 && j == n-1) continue;
                if (board[i][j] == 'X') continue;
                long long best = -1, cnt = 0;
                for (int k = 0; k < 3; k++) {
                    int ni = i + di[k], nj = j + dj[k];
                    if (ni < n && nj < n && dpSum[ni][nj] != -1) {
                        if (dpSum[ni][nj] > best) { best = dpSum[ni][nj]; cnt = dpCount[ni][nj]; }
                        else if (dpSum[ni][nj] == best) cnt = (cnt + dpCount[ni][nj]) % MOD;
                    }
                }
                if (best == -1) continue;
                int val = (board[i][j] == 'S') ? 0 : board[i][j] - '0';
                dpSum[i][j] = best + val;
                dpCount[i][j] = cnt;
            }
        }
        if (dpSum[0][0] == -1) return {0, 0};
        return {(int)(dpSum[0][0] % MOD), (int)dpCount[0][0]};
    }
};
