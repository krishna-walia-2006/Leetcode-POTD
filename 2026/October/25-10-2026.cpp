class Solution {
    int m,n;
    int dfs(vector<vector<int>>& grid,int i,int j) {
        if(i>=m || i<0 || j<0 || j>=n) return false;
        if(grid[i][j]==1) return true;
        grid[i][j]=1;
        bool up_closed=dfs(grid,i-1,j);
        bool left_closed=dfs(grid,i,j-1);
        bool right_closed=dfs(grid,i,j+1);
        bool bottom_closed=dfs(grid,i+1,j);
        return bottom_closed && right_closed && left_closed && up_closed;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==0) {
                    if(dfs(grid,i,j)) ans++;
                }
            }
        }
        return ans;
    }
};
