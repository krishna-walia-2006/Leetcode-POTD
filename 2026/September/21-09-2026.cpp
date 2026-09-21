class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k,0),prev(k,0);
        int n=nums.size();
        for(int i=0;i<n;i++) {
            vector<long long> curr(k,0);
            curr[nums[i]%k]++;
            for(int oldRem=0;oldRem<k;oldRem++) {
                long long newRem = ((long long)oldRem*nums[i])%k;
                curr[newRem]+=prev[oldRem]; 
            }
            prev=move(curr);
            for(int x=0;x<k;x++) result[x]+=prev[x];
        }
        return result;

    }
};