class Solution {
    int m,n;
    int f(int i,int j,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp,int k,int cost) {
        if(i>=m || j>=n) return INT_MIN;
        int currCost=cost+(grid[i][j]>0);
        if(currCost>k) return INT_MIN;
        if(i==m-1 && j==n-1) return grid[i][j];
        
        if(dp[i][j][cost]!=-1) return dp[i][j][cost];
        int down=f(i+1,j,grid,dp,k,currCost);
        int right=f(i,j+1,grid,dp,k,currCost);
        if(down==INT_MIN && right==INT_MIN) return dp[i][j][cost]=INT_MIN;
        return dp[i][j][cost]=max(down,right)+grid[i][j];
    } 
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>> (n,vector<int>(k+1,-1)));
        int result=f(0,0,grid,dp,k,0);
        return result == INT_MIN ? -1 : result;
    }
};
