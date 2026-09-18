class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<string> result;
        int n=s.size();
        vector<int> start(26,-1),end(26,0);
        vector<bool> isValid(26,true);
        for(int i=0;i<n;i++) {
            int idx=s[i]-'a';
            if(start[idx]==-1) start[idx]=i; 
            end[idx]=i;
        }
        for(int i=0;i<26;i++) {
            if(start[i]==-1) continue;
            for(int j=start[i];j<=end[i];j++) {
                if(start[s[j]-'a']<start[i]) {
                    isValid[i]=false;
                    break;
                }
                end[i]=max(end[i],end[s[j]-'a']);
            }
        }
        int lastStartTaken=INT_MAX;
        for(int i=n-1;i>=0;i--) {
            int idx=s[i]-'a';
            if(!isValid[idx]) continue;
            if(i==start[idx] && end[idx]<lastStartTaken) {
                result.push_back(s.substr(i,end[idx]-i+1));
                lastStartTaken=i;
            }
        }
        return result;
    }
};