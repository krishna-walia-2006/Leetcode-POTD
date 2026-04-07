class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
    int m = coins.size(), n = coins[0].size();

    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));

    // Base case
    for(int neu = 0; neu < 3; neu++) {
        if(coins[m-1][n-1] < 0 && neu > 0)
            dp[m-1][n-1][neu] = 0;
        else
            dp[m-1][n-1][neu] = coins[m-1][n-1];
    }

    for(int i = m-1; i >= 0; i--) {
        for(int j = n-1; j >= 0; j--) {

            if(i == m-1 && j == n-1) continue;

            for(int neu = 0; neu < 3; neu++) {

                int temp1 = (i+1 < m) ? dp[i+1][j][neu] : INT_MIN;
                int temp2 = (j+1 < n) ? dp[i][j+1][neu] : INT_MIN;

                int bestNext = max(temp1, temp2);

                int notTake = (bestNext == INT_MIN) 
                              ? INT_MIN 
                              : coins[i][j] + bestNext;

                int Take = INT_MIN;

                if(coins[i][j] < 0 && neu > 0) {
                    int t1 = (i+1 < m) ? dp[i+1][j][neu-1] : INT_MIN;
                    int t2 = (j+1 < n) ? dp[i][j+1][neu-1] : INT_MIN;

                    Take = max(t1, t2);
                }

                dp[i][j][neu] = max(Take, notTake);
            }
        }
    }

    return dp[0][0][2];
}
};
