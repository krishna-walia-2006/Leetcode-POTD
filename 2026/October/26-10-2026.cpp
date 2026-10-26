class Solution {
    int m,n,K;
    int dfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& visited) {
        if(i>=m || i<0 || j<0 || j>=n || visited[i][j] || grid[i][j]==0) return 0;
        visited[i][j]=true;
        int leftScore = dfs(i,j-1,grid,visited);
        int rightScore = dfs(i,j+1,grid,visited);
        int upScore = dfs(i-1,j,grid,visited);
        int bottomScore = dfs(i+1,j,grid,visited);
        return (leftScore + rightScore + upScore + bottomScore + grid[i][j])%K;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        K=k,m=grid.size(),n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool> (n,false));
        int ans=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]!=0 && !visited[i][j]) {
                    int score=dfs(i,j,grid,visited);
                    if(score%k==0) ans++;                    
                }
            }
        }
        return ans;

    }
};
