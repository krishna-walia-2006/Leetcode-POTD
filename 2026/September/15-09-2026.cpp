class Solution {
    void Palindrome(string s,vector<vector<bool>>& isPalindrome) {
        int n=s.size();
        for(int l=1;l<=n;l++) {
            for(int i=0;i+l<=n;i++) {
                int j=i+l-1;
                if(i==j) {
                    isPalindrome[i][j]=true;
                } else if(j==(i+1)) {
                    isPalindrome[i][j]=s[i]==s[j];
                } else {
                    isPalindrome[i][j]=s[i]==s[j] && isPalindrome[i+1][j-1];
                }
            }
        }
    }
public:
    int maxPalindromes(string s, int k) {
        int n=s.size();
        if(k==1) return n;
        vector<vector<int>> dp(n,vector<int> (n,0));
        vector<vector<bool>> isPalindrome(n,vector<bool> (n,false));
        Palindrome(s,isPalindrome);
        for(int i=n-1;i>=0;i--) {
            for(int j=n-1;j>=0;j--) {
                int take=0,increaseSize=0,slide=0;
                if(isPalindrome[i][j] && (j-i+1)>=k) {
                    take=1;
                    if(j+1<n && j+k<n) take+=dp[j+1][j+k];
                }
                if(j+1<n) increaseSize=dp[i][j+1];
                if(i+1<n && j+1<n) slide = dp[i+1][j+1];
                dp[i][j]=max({take,increaseSize,slide});
            }
        }
        return dp[0][k-1];
    }
};