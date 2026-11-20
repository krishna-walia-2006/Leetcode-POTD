class Solution {
    int find(int val,int start,vector<int> &nums) {
        int j=lower_bound(nums.begin()+start,nums.end(),val)-nums.begin();
        if(j<nums.size() && nums[j]==val) {
            return j;
        }
        return -1;
    }
public:
    int maxSelectedElements(vector<int>& nums) {
        int result=1,n=nums.size();
        vector<vector<int>> dp(n+1,vector<int> (2,0));
        sort(nums.begin(),nums.end());
        for(int i=n-1;i>=0;i--) {
            for(int inc=0;inc<=1;inc++) {
                int len=1;
                int currVal = nums[i]+inc;
                int j=find(currVal+1,i+1,nums);
                if(j!=-1) {
                    len=max(len,1+dp[j][0]);
                }
                j=find(currVal,i+1,nums);
                if(j!=-1) {
                    len=max(len,1+dp[j][1]);
                }
                dp[i][inc]=len;
                result=max({result,dp[i][inc]});
            }
        }
        return result;
    }
};
