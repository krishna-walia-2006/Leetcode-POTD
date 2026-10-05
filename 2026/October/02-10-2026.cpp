class Solution {
    void solve(int openCount,int closeCount,int& n,vector<string>& ans,string& curr) {
        if(openCount==0 && closeCount==0) ans.push_back(curr);
        
        if(openCount>0) {
            curr.push_back('(');
            solve(openCount-1,closeCount,n,ans,curr);
            curr.pop_back();
        }
        if(closeCount>openCount) {
            curr.push_back(')');
            solve(openCount,closeCount-1,n,ans,curr);
            curr.pop_back();
        }
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;
        solve(n,n,n,ans,curr);
        return ans;
    }
}