class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m=queries.size();
        sort(logs.begin(),logs.end(),[] (vector<int> a,vector<int> b) {
            return a[1]<b[1];
        });
        vector<int> ans(m);
        vector<pair<int,int>> q;
        unordered_map<int,int> freq;
        for(int i=0;i<queries.size();i++) q.push_back({queries[i],i});
        sort(q.begin(),q.end());
        int l=0,r=0,L=logs.size(),active=0;
        for(auto& [time,idx]:q) {
            while(r<L && logs[r][1]<=time) {
                int s=logs[r][0];
                if(++freq[s]==1) active++;
                r++;
            }
            while(l<r && logs[l][1]<time-x) {
                int s=logs[l][0];
                if(--freq[s]==0) active--;
                l++;
            }
            ans[idx]=n-active;
        }  
        return ans;
    }
};
