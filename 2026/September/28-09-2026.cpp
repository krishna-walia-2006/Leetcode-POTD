class Solution {
public:
    int maxDepth(string s) {
        int count=0,result=0;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='(') {
                count++;
                result=max(result,count);
            }
            if(s[i]==')') count--;
        }
        return result;
    }
};