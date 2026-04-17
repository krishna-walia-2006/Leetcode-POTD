class Solution {
    int rev(int n) {
        int sum=0;
        while(n>0) {
            int digit=n%10;
            sum=sum*10+digit;
            n=n/10;
        }
        return sum;
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int ans=INT_MAX;
        for(int i=0;i<n;i++) {
            if(mp.count(nums[i])) {
                ans=min(ans,i-mp[nums[i]]);
            }
            mp[rev(nums[i])]=i;
        }
        return ans==INT_MAX?-1:ans;
    }
};
