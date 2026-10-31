class Solution {
    int m, n, MOD = 1e9 + 7;
    vector<vector<int>> memo;

    int dfs(int i, int j, vector<vector<int>>& grid) {
        if (i >= m || j >= n) return 0;
        if (i == m - 1 && j == n - 1) return 1;
        
        if (memo[i][j] != -1) return memo[i][j];

        int right = 0, down = 0;
        
        int x = i, y = j + 1;
        int dir = 0;
        while (x < m && y < n && grid[x][y] == 1) {
            if (dir == 0) {
                x++;
                dir = 1;
            } else {
                y++;
                dir = 0;
            }
        }
        right = dfs(x, y, grid);
        
        x = i + 1;
        y = j;
        dir = 1;
        while (x < m && y < n && grid[x][y] == 1) {
            if (dir == 1) {
                y++;
                dir = 0;
            } else {
                x++;
                dir = 1;
            }
        }
        down = dfs(x, y, grid);
        
        return memo[i][j] = (down + right) % MOD;
    }
    
public:
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        memo.assign(m, vector<int>(n, -1));
        
        return dfs(0, 0, grid);
    }
};
