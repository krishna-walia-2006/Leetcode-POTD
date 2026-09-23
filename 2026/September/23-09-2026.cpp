class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long sum=0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];

        long long remaining = sum - x;
        int i=0,j=0,ans=-1,n=nums.size();
        long long curr = 0;
        while(j<n) {
            curr+=nums[j];
            while(curr>remaining && i<=j) curr-=nums[i++];
            if(curr==remaining) ans=max(ans,j-i+1);
            j++;
        }
        return ans<0?ans:n-ans;
    }
};
