// LeetCode 3336. Find the Number of Subsequences with Equal GCD
// Daily challenge: 2026-07-14
//
#include <vector>
#include <map>
#include <numeric>
using namespace std;

class Solution {
public:
    int subsequencePairGCDCount(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        map<pair<int,int>, long long> dp;
        dp[{0, 0}] = 1;
        for (int x : nums) {
            map<pair<int,int>, long long> ndp = dp;
            for (auto& [key, cnt] : dp) {
                int g1 = key.first, g2 = key.second;
                int ng1 = (g1 == 0) ? x : (int)gcd(g1, x);
                int ng2 = (g2 == 0) ? x : (int)gcd(g2, x);
                ndp[{ng1, g2}] = (ndp[{ng1, g2}] + cnt) % MOD;
                ndp[{g1, ng2}] = (ndp[{g1, ng2}] + cnt) % MOD;
            }
            dp = move(ndp);
        }
        long long ans = 0;
        for (auto& [key, cnt] : dp) {
            if (key.first == key.second && key.first != 0) ans = (ans + cnt) % MOD;
        }
        return (int)ans;
    }
};
