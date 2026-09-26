class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        for(auto& i:knowledge) mp[i[0]]=i[1];
        string res="",key="";
        for(int i=0;i<s.size();i++) {
            if(s[i]=='(') {
                i++;
                while(s[i]!=')') key+=s[i++];
                cout<<key;
                if(mp.find(key)!=mp.end()) res+=mp[key];
                else res+='?';
                key.clear(); 
            }
            else res+=s[i];
        }
        return res;
    }
};