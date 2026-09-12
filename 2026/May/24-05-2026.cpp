// LeetCode 1340. Jump Game V
// Daily challenge: 2026-05-24
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return arr[a] < arr[b]; });

        vector<int> dp(n, 1);
        for (int i : idx) {
            for (int dir = -1; dir <= 1; dir += 2) {
                for (int step = 1; step <= d; step++) {
                    int j = i + dir * step;
                    if (j < 0 || j >= n) break;
                    if (arr[j] >= arr[i]) break;
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
