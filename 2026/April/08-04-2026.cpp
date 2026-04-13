class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int MOD = 1e9+7;
        for(int i=0;i<queries.size();i++) {
            int idx = queries[i][0];
            while(idx <= queries[i][1]) {
                nums[idx] = (1LL * nums[idx] * queries[i][3]) % MOD;
                idx += queries[i][2];
            }
        }
        int ans = 0;
        for(int i:nums) ans=ans^i;
        return ans;
    }
};
