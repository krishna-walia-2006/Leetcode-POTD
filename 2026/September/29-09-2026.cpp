class Solution {
    int m,n;
    int dp[101][101][202];
    bool solve(int i,int j,int count,vector<vector<char>>& grid) {
        count+=(grid[i][j]=='(')?1:-1;
        if(count<0) return false;
        if(i==m-1 && j==n-1) return count==0;
        bool right=false,down=false;
        if(dp[i][j][count]!=-1) return dp[i][j][count]; 
        if(j+1<n) right=solve(i,j+1,count,grid);
        if(i+1<m) down=solve(i+1,j,count,grid);
        return dp[i][j][count]=down||right;
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        if(grid[0][0]==')' || grid[m-1][n-1]=='(' || (m+n-1)%2!=0) return false;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,grid);
    }
};