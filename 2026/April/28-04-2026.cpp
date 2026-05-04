class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m=grid.size(),n=grid[0].size();
        vector<int> arr;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                arr.push_back(grid[i][j]);
            }
        }
        int base=arr[0];
        for(int i:arr) {
            if((i-base)%x!=0) return -1;
        }
        sort(arr.begin(),arr.end());
        int median=arr[arr.size()/2];
        int ans=0;
        for(int i:arr) {
            ans+=abs((i-median)/x);
        }
        return ans;
   }
};
