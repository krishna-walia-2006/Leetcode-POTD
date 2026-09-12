// LeetCode 3751. Total Waviness of Numbers in Range I
// Daily challenge: 2026-06-04
#include <string>
using namespace std;

class Solution {
    int waviness(long long num) {
        string s = to_string(num);
        int n = s.size();
        if (n < 3) return 0;
        int cnt = 0;
        for (int i = 1; i < n - 1; i++) {
            int d = s[i]-'0', pd = s[i-1]-'0', nd = s[i+1]-'0';
            if ((d > pd && d > nd) || (d < pd && d < nd)) cnt++;
        }
        return cnt;
    }
public:
    long long totalWaviness(int num1, int num2) {
        long long total = 0;
        for (long long x = num1; x <= num2; x++) total += waviness(x);
        return total;
    }
};
