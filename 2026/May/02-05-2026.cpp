class Solution {
public:
    int rotatedDigits(int n) {
        int ans=0;
        for(int i=1;i<=n;i++) {
            int currans=0,temp=i;
            while(temp!=0) {
                int digit=temp%10;
                if(digit==0 || digit==1 || digit==8) {}
                else if(digit==2 || digit==5 || digit==6 || digit==9) {
                    currans=1;
                }
                else {
                    currans=0;
                    break;
                }
                temp/=10;
            }
            ans+=currans;
        }
        return ans;
    }
};
