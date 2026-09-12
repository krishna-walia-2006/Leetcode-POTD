// LeetCode 3286. Find a Safe Walk Through a Grid
// Daily challenge: 2026-07-02
//

#include <vector>
#include <deque>
#include <climits>
using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = grid[0][0];
        deque<pair<int,int>> dq;
        dq.push_back({0, 0});
        int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        while (!dq.empty()) {
            auto [r, c] = dq.front(); dq.pop_front();
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int nd = dist[r][c] + grid[nr][nc];
                    if (nd < dist[nr][nc]) {
                        dist[nr][nc] = nd;
                        if (grid[nr][nc] == 0) dq.push_front({nr, nc});
                        else dq.push_back({nr, nc});
                    }
                }
            }
        }
        return health - dist[n-1][m-1] > 0;
    }
};
