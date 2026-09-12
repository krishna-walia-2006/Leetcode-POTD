// LeetCode 3754. Concatenate Non-Zero Digits and Multiply by Sum I
// Daily challenge: 2026-07-07
#include <string>
using namespace std;

class Solution {
public:
    long long concatenatedDigits(int n) {
        string s = to_string(n);
        long long x = 0, sum = 0;
        for (char c : s) {
            int d = c - '0';
            sum += d;
            if (d != 0) x = x * 10 + d;
        }
        return x * sum;
    }
};
