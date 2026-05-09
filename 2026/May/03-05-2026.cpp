class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        string temp=s+s;
        int n=s.size();
        for(int i=0;i<2*n;i++) {
            bool match=false;
            for(int j=0;j<n;j++) {
                if(temp[i+j]==goal[j]) {
                    match=true;
                }
                else {
                    match=false;
                    break;
                }
            }
            if(match) return true;
        }
        return false;
    }
};
