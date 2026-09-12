// LeetCode 3756. Concatenate Non-Zero Digits and Multiply by Sum II
// Daily challenge: 2026-07-08
//

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> concatenatedDigits(string s, vector<vector<int>>& queries) {
        const long long MOD = 1e9 + 7;
        int m = s.size();
        vector<long long> val(m + 1, 0), sumDigits(m + 1, 0);
        vector<int> cnt(m + 1, 0);
        for (int i = 0; i < m; i++) {
            int d = s[i] - '0';
            sumDigits[i+1] = sumDigits[i] + d;
            if (d != 0) {
                val[i+1] = (val[i] * 10 + d) % MOD;
                cnt[i+1] = cnt[i] + 1;
            } else {
                val[i+1] = val[i];
                cnt[i+1] = cnt[i];
            }
        }
        vector<long long> pow10(m + 1);
        pow10[0] = 1;
        for (int i = 1; i <= m; i++) pow10[i] = pow10[i-1] * 10 % MOD;

        vector<int> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            int k = cnt[r+1] - cnt[l];
            long long x = ((val[r+1] - val[l] * pow10[k]) % MOD + MOD) % MOD;
            long long sum = sumDigits[r+1] - sumDigits[l];
            ans.push_back((int)((x * sum) % MOD));
        }
        return ans;
    }
};
