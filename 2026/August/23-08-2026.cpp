// LeetCode 1927. Sum Game
// Daily challenge: 2026-08-23
#include <string>
using namespace std;

class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;
        long long sum1 = 0, sum2 = 0;
        int q1 = 0, q2 = 0;
        for (int i = 0; i < half; i++) {
            if (num[i] == '?') q1++; else sum1 += num[i] - '0';
        }
        for (int i = half; i < n; i++) {
            if (num[i] == '?') q2++; else sum2 += num[i] - '0';
        }
        int totalQ = q1 + q2;
        long long diff = sum1 - sum2;
        if (totalQ % 2 == 1) return true;
        return diff != (long long)(q2 - q1) / 2 * 9;
    }
};
