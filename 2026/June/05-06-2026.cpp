// LeetCode 3753. Total Waviness of Numbers in Range II
// Daily challenge: 2026-06-05
//

#include <string>
#include <vector>
using namespace std;

class Solution {
    string s;
    int n;
    vector<vector<vector<pair<long long,long long>>>> memo; // [pos][prevDigit][prevDir] -> {count, sum}
    vector<vector<vector<bool>>> vis;

    pair<long long,long long> dp(int pos, int prevDigit, int prevDir, bool started, bool tight) {
        if (pos == n) return {1, 0};
        if (!tight && started && vis[pos][prevDigit][prevDir]) return memo[pos][prevDigit][prevDir];

        int limit = tight ? (s[pos]-'0') : 9;
        long long totalCount = 0, totalSum = 0;
        for (int d = 0; d <= limit; d++) {
            bool nstarted = started || d > 0;
            bool ntight = tight && (d == limit);
            if (!started) {
                if (!nstarted) {
                    auto [c, sm] = dp(pos+1, 0, 0, false, ntight);
                    totalCount += c; totalSum += sm;
                } else {
                    auto [c, sm] = dp(pos+1, d, 0, true, ntight);
                    totalCount += c; totalSum += sm;
                }
            } else {
                int ndir = (d > prevDigit) ? 1 : (d < prevDigit ? 2 : 3);
                long long bonus = 0;
                if ((prevDir == 1 && ndir == 2) || (prevDir == 2 && ndir == 1)) bonus = 1;
                auto [c, sm] = dp(pos+1, d, ndir, true, ntight);
                totalCount += c;
                totalSum += sm + bonus * c;
            }
        }
        if (!tight && started) {
            vis[pos][prevDigit][prevDir] = true;
            memo[pos][prevDigit][prevDir] = {totalCount, totalSum};
        }
        return {totalCount, totalSum};
    }

    long long helper(long long num) {
        if (num < 0) return 0;
        s = to_string(num);
        n = s.size();
        memo.assign(n, vector<vector<pair<long long,long long>>>(10, vector<pair<long long,long long>>(4, {0,0})));
        vis.assign(n, vector<vector<bool>>(10, vector<bool>(4, false)));
        auto [c, sm] = dp(0, 0, 0, false, true);
        return sm;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return helper(num2) - helper(num1 - 1);
    }
};
