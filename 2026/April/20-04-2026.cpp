class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int ans=INT_MIN;
        for(int i=n-1;i>=1;i--) {
            if(colors[i]!=colors[0]) {
                ans=max(ans,i);
            }
        }
        for(int i=0;i<n-1;i++) {
            if(colors[i]!=colors[n-1]) {
                ans=max(ans,abs(i-(n-1)));
            }
        }
        return ans;
    }
};
