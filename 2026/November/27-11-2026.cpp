class Solution {
    int mini=2e9;
    int solve(int n,int W,vector<vector<int>>& items,vector<int>& factors,vector<vector<int>>& dp) {
        if(W==0) return 0;
        if(n>=items.size()) return W/mini;
        if(dp[n][W]!=-1) return dp[n][W];
        int pick=0;
        if(items[n][1]<=W) {
            pick=factors[n]+solve(n+1,W-items[n][1],items,factors,dp);
        }
        int skip=solve(n+1,W,items,factors,dp);
        return dp[n][W]=max(pick,skip);
    }
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        vector<int> factors(n,0);
        vector<vector<int>> dp(n,vector<int> (budget+1,-1));
        for(int i=0;i<n;i++) {
            mini=min(mini,items[i][1]);
            for(int j=0;j<n;j++) {
                if(items[j][0]%items[i][0]==0) factors[i]++;
            }
        }
        return solve(0,budget,items,factors,dp);
    }
};
