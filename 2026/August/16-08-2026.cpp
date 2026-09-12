// LeetCode 2029. Stone Game IX
// Daily challenge: 2026-08-16
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0, 0, 0};
        for (int x : stones) cnt[x % 3]++;
        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        } else {
            return abs(cnt[1] - cnt[2]) > 2;
        }
    }
};
