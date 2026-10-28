class Solution {
    int m,n;
    vector<vector<vector<int>>> dp;
    int dfs(int i,int j,int temp,vector<vector<int>>& grid) {
        if(i>=m || j>=n) return 1e9;
        temp^=grid[i][j];
        if(i==m-1 && j==n-1) return temp;
        if(dp[i][j][temp] != -1) return dp[i][j][temp];
        int right = dfs(i,j+1,temp,grid);
        int down = dfs(i+1,j,temp,grid);
        return dp[i][j][temp] = min(right,down);
    }
public:
    int minCost(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(1024, -1)));
        return dfs(0,0,0,grid);
    }
};
