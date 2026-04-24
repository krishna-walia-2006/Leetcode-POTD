class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n=moves.size(),lCount=0,rCount=0,sCount=0;
        for(int i=0;i<n;i++) {
            if(moves[i]=='L') lCount++;
            else if(moves[i]=='R') rCount++;
            else sCount++;
        }
        if(lCount>=rCount) return lCount+sCount-rCount;
        else return rCount+sCount-lCount;

    }
};
