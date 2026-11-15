class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int ans=0,preSum=0,even=1,odd=0,n=arr.size(),sum=0,M=1e9+7;
        for(int i=0;i<n;i++) {
            preSum+=arr[i];
            if(preSum%2==0) {
                ans=(ans+odd)%M;
                even++;
            } else {
                ans=(ans+even)%M;
                odd++;
            }
        }
        return ans;
    }
};