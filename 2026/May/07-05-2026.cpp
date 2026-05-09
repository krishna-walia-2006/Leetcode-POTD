class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0),preMax(n,0),postMin(n,0);
        preMax[0]=nums[0];
        for(int i=1;i<n;i++) {
            preMax[i]=max(preMax[i-1],nums[i]);
        }
        postMin[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--) {
            postMin[i]=min(postMin[i+1],nums[i]);
        }
        ans[n-1]=preMax[n-1];
        for(int i=n-2;i>=0;i--) {
            if(postMin[i+1]<preMax[i]) {
                ans[i]=ans[i+1];
            }
            else ans[i]=preMax[i];
        }
        return ans;
    }
    
};
