class Solution {
public:
    bool checkString(string s) {
        int lastA=-1,firstB=-1;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='a') lastA=i;
            else if(firstB==-1) firstB=i;
        }
        if(lastA==-1 || firstB==-1) return true;
        return lastA<firstB;
    }
};
