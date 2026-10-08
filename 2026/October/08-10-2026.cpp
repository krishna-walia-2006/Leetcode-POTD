class Solution {
public:
    string removeOuterParentheses(string s) {
        int level = 0;
        string ans="";
        for(char ch:s) {
            if(ch=='(') {
                if(level>0) {
                    ans+='(';
                }
                level++;
            }
            else {
                level--;
                if(level>0) {
                    ans+=')';
                }
            }
        }
        return ans;
    }
};
