class Solution {
public:
    vector<vector<vector<int>>> dirs = {
        {},
        {{0,-1},{0,1}},      // 1
        {{-1,0},{1,0}},      // 2
        {{0,-1},{1,0}},      // 3
        {{0,1},{1,0}},       // 4
        {{0,-1},{-1,0}},     // 5
        {{0,1},{-1,0}}       // 6
    };

    bool isValid(int i,int j,int m,int n){
        return i>=0 && j>=0 && i<m && j<n;
    }

    bool dfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& vis){
        int m=grid.size(), n=grid[0].size();
        
        if(i==m-1 && j==n-1) return true;
        
        vis[i][j]=true;
        
        for(auto d: dirs[grid[i][j]]) {
            int ni=i+d[0], nj=j+d[1];
            
            if(!isValid(ni,nj,m,n) || vis[ni][nj]) continue;
            
            // check reverse connection
            for(auto back: dirs[grid[ni][nj]]) {
                if(ni+back[0]==i && nj+back[1]==j) {
                    if(dfs(ni,nj,grid,vis)) return true;
                }
            }
        }
        
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n,false));
        return dfs(0,0,grid,vis);
    }
};
