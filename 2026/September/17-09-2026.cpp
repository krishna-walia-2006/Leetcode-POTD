class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        
        vector<int> bestTillNow(n,INT_MAX);
        int curr=0,i=0,bestMin=INT_MAX;
        for(int j=0;j<n;j++) {
            curr+=arr[j];
            while(i<n && curr>target) curr-=arr[i++];
            if(curr==target) {
                cout<<i<<" "<<j<<" "<<curr<<endl;
                int length=j-i+1;
                if(i>0 && bestTillNow[i-1]!=INT_MAX)
                bestMin=min(bestMin,length+bestTillNow[i-1]);
                bestTillNow[j]=length;
            }
            if(j>0) bestTillNow[j]=min(bestTillNow[j],bestTillNow[j-1]);
        }
        return bestMin==INT_MAX?-1:bestMin;
    }
};