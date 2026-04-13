class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        unordered_map<int,vector<int>> mp;
        for(int i = 0;i < n;i++) {
            mp[nums[i]].push_back(i);
            if(mp[nums[i]].size() >= 3) {
                // vector<int> vec = mp[nums[i]];
                int size = mp[nums[i]].size();
                ans = min(ans,abs(i-mp[nums[i]][size-3]));
            }
        } 
        return ans==INT_MAX?-1:2*ans;
    }
};
