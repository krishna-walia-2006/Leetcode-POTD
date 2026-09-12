// LeetCode 1840. Maximum Building Height
// Daily challenge: 2026-06-20
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end());
        int m = restrictions.size();

        for (int i = 1; i < m; i++) {
            restrictions[i][1] = min(restrictions[i][1],
                restrictions[i-1][1] + (restrictions[i][0] - restrictions[i-1][0]));
        }
        for (int i = m-2; i >= 0; i--) {
            restrictions[i][1] = min(restrictions[i][1],
                restrictions[i+1][1] + (restrictions[i+1][0] - restrictions[i][0]));
        }

        int ans = restrictions[0][1];
        for (int i = 1; i < m; i++) {
            int id1 = restrictions[i-1][0], h1 = restrictions[i-1][1];
            int id2 = restrictions[i][0], h2 = restrictions[i][1];
            int d = id2 - id1;
            int peak = (h1 + h2 + d) / 2;
            ans = max({ans, h1, h2, peak});
        }
        int lastId = restrictions[m-1][0], lastH = restrictions[m-1][1];
        ans = max(ans, lastH + (n - lastId));
        return ans;
    }
};
