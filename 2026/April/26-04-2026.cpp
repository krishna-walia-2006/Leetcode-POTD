class Solution {
    int drow[4]={-1,0,1,0};
    int dcol[4]={0,-1,0,1};
    bool cycle(int r,int c,int prev_r,int prev_c,vector<vector<char>>& grid,vector<vector<bool>>& visited) {
        if(visited[r][c]) return true;
        visited[r][c]=true;
        for(int i=0;i<4;i++) {
            int new_r=r+drow[i];
            int new_c=c+dcol[i];

            if(new_r<grid.size() && new_c<grid[0].size() && new_r>=0 && new_c>=0 && grid[new_r][new_c]==grid[r][c]) {
                if(new_r==prev_r && new_c==prev_c) continue;
                if(cycle(new_r,new_c,r,c,grid,visited)) return true;
            }
        }
        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool> (n,false));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(!visited[i][j] && cycle(i,j,i,j,grid,visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};
