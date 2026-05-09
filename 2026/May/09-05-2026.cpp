class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int r1 = 0, r2 = m - 1, c1 = 0, c2 = n - 1;
        vector<int> arr;
        vector<vector<int>> ans = grid;
        
        while(r1 < r2 && c1 < c2) {
            for(int i = c1; i <= c2 - 1; i++) {
                arr.push_back(grid[r1][i]);
            }
            for(int i = r1 ; i <= r2 - 1; i++) {
                arr.push_back(grid[i][c2]);
            }
            for(int i = c2;i >= c1 + 1; i--) {
                arr.push_back(grid[r2][i]);
            }
            for(int i = r2;i >= r1 + 1; i--) {
                arr.push_back(grid[i][c1]);
            }
            int rot = k % arr.size();
            reverse(arr.begin(),arr.begin()+rot);
            reverse(arr.begin()+rot,arr.end());
            reverse(arr.begin(),arr.end());
            int j=0;
            for(int i = c1; i <= c2 - 1; i++) {
                ans[r1][i] = arr[j];
                j++;
            }
            for(int i = r1 ; i <= r2 - 1; i++) {
                ans[i][c2] = arr[j];
                j++;
            }
            for(int i = c2;i >= c1 + 1; i--) {
                ans[r2][i] = arr[j];
                j++;
            }
            for(int i = r2;i >= r1 + 1; i--) {
                ans[i][c1] = arr[j];
                j++;
            }
            arr.clear();
            r1++;
            r2--;
            c1++;
            c2--;
        }      
        return ans;
    }
};
