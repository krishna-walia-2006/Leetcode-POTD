class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int total=1,m=grid.size(),n=grid[0].size(),MOD=12345;
        vector<vector<int>> ans(m,vector<int>(n,1));
        long long suffix=1;
        for(int i=m-1;i>=0;i--) {
            for(int j=n-1;j>=0;j--) {
                ans[i][j]=suffix;
                suffix=(suffix*grid[i][j])%MOD;
            }
        }
        long long prefix=1;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                ans[i][j]=(ans[i][j]*prefix)%MOD;
                prefix=(prefix*grid[i][j])%MOD;
            }
        }
        return ans;
    }
};
