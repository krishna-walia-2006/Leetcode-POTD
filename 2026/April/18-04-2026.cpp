class Solution {
public:
    int mirrorDistance(int n) {
        int temp=n,revn=0;
        while(temp!=0) {
            revn=revn*10+temp%10;
            temp/=10;
        }
        return abs(n-revn);
    }
};
