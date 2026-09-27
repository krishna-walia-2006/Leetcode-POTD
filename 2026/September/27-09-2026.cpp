class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> openBracketIndex;
        int n=s.size();
        vector<int> door(n);
        int dir=1;
        string res="";
        for(int i=0;i<n;i++) {
            if(s[i]=='(') openBracketIndex.push(i);
            else if(s[i]==')') {
                int j=openBracketIndex.top();
                openBracketIndex.pop();
                door[i]=j;
                door[j]=i;
            }
        }

        for(int i=0;i<n;i+=dir) {
            if(s[i]=='(' || s[i]==')') {
                dir=-dir;
                i=door[i];
            }
            else {
                res+=s[i];
            }
        }
        return res;
    }
};