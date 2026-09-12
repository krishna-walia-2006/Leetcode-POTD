
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        int mod = 1e9 + 7;
        vector<int> last(26, -1);
        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            dp[i] = (2LL * dp[i-1]) % mod;
            if (last[s[i-1] - 'a'] != -1) {
                dp[i] = (dp[i] - dp[last[s[i-1] - 'a'] - 1] + mod) % mod;
            }
            last[s[i-1] - 'a'] = i;
        }

        dp[n]--;
        if (dp[n] < 0) dp[n] += mod;
        return dp[n];
    }
};
