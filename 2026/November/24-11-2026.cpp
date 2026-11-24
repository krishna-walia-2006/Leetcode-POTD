class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans=0,n=nums.size();
        for(int i=0;i<n;i++) {
            long long gcdi=nums[i],prod=nums[i],lcmi=nums[i];
            for(int j=i+1;j<n;j++) {
                gcdi=gcd(gcdi,nums[j]);
                prod=prod*nums[j];
                lcmi=lcm(lcmi,nums[j]);
                if(prod==lcmi*gcdi) ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};
