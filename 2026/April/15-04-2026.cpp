class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int c=0,n=words.size();
        while(c!=n) {
            if(words[(startIndex+c)%n]==target) {
                return c;
            }
            if(words[(startIndex-c+n)%n]==target) {
                return c;
            }
            c++;
        }
        return -1;
    }
};
