// LeetCode 2812. Find the Safest Path in a Grid
// Daily challenge: 2026-07-01
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return 0;
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int,int>> q;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1) { dist[i][j] = 0; q.push({i, j}); }

        int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        priority_queue<tuple<int,int,int>> pq;
        pq.push({dist[0][0], 0, 0});
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vis[0][0] = true;
        while (!pq.empty()) {
            auto [safe, r, c] = pq.top(); pq.pop();
            if (r == n - 1 && c == n - 1) return safe;
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc]) {
                    vis[nr][nc] = true;
                    pq.push({min(safe, dist[nr][nc]), nr, nc});
                }
            }
        }
        return 0;
    }
};
