class Solution {
public:
    int minMoves2(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int median=arr[arr.size()/2];
        int ans=0;
        for(int i:arr) {
            ans+=abs((i-median));
        }
        return ans;
    }
};