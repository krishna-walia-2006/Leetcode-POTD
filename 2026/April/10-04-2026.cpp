// Krish
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++) {
            mp[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
        for(auto i1:mp) {
            if(i1.second.size()>=3) {
                auto i=i1.second;
                for(int k=0;k+2<i.size();k++) {
                    ans=min(ans,abs(i[k]-i[k+1]) + abs(i[k+2]-i[k+1]) + abs(i[k]-i[k+2]));
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};
