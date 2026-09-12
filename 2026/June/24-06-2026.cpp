// LeetCode 3700. Number of ZigZag Arrays II
// Daily challenge: 2026-06-24
//

#include <vector>
using namespace std;

class Solution {
public:
    int numberOfArrays(int n, int l, int r) {
        const long long MOD = 1e9 + 7;
        int R = r - l + 1;
        if (n == 1) return R % MOD;

        vector<long long> up(R, 1), down(R, 1);
        for (int i = 2; i <= n; i++) {
            vector<long long> prefDown(R+1, 0), prefUp(R+1, 0);
            for (int v = 0; v < R; v++) {
                prefDown[v+1] = prefDown[v] + down[v];
                prefUp[v+1] = prefUp[v] + up[v];
            }
            long long totalUp = prefUp[R];
            vector<long long> newUp(R), newDown(R);
            for (int v = 0; v < R; v++) {
                newUp[v] = prefDown[v] % MOD;
                newDown[v] = (totalUp - prefUp[v+1] + MOD) % MOD;
            }
            up = newUp; down = newDown;
        }
        long long ans = 0;
        for (int v = 0; v < R; v++) ans = (ans + up[v] + down[v]) % MOD;
        return (int)ans;
    }
};
