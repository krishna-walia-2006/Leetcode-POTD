class Solution {
    typedef tuple<int,int> t;
    typedef tuple<long,int,int> T;
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int m=servers.size(),n=tasks.size();
        vector<int> ans(n);
        priority_queue<t, vector<t>, greater<t>> freeServers;
        priority_queue<T, vector<T>, greater<T>> busyServers;
        for(int i=0;i<m;i++) {
            freeServers.push({servers[i],i});
        }

        for(int j=0;j<n;j++) {
            while(!busyServers.empty() && get<0>(busyServers.top())<=j) {
                auto [fTime,wt,idx] = busyServers.top();
                busyServers.pop();
                freeServers.push({wt,idx});
            }
            if(freeServers.empty()) {
                auto [fTime,wt,idx] = busyServers.top();
                busyServers.pop();
                busyServers.push({fTime+tasks[j],wt,idx});
                ans[j]=idx;
            }
            else {
                auto [wt,idx] = freeServers.top();
                freeServers.pop();
                busyServers.push({j+tasks[j],wt,idx});
                ans[j]=idx;
            }
        }
        return ans;
    }
};
