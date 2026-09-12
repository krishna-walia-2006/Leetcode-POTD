// LeetCode 3614. Process String with Special Operations II
// Daily challenge: 2026-06-17
//
// 
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

class Solution {
public:
    char processStringResult(string s, long long k) {
        int n = s.size();
        if (n == 0) return '.';
        vector<long long> lengths(n);
        long long len = 0;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (islower((unsigned char)c)) len += 1;
            else if (c == '*') len = max(0LL, len - 1);
            else if (c == '#') len *= 2;
            lengths[i] = len;
        }
        if (k < 0 || k >= lengths[n-1]) return '.';

        bool rev = false;
        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];
            if (islower((unsigned char)c)) {
                long long L = lengths[i];
                if (!rev) {
                    if (k == L - 1) return c;
                } else {
                    if (k == 0) return c;
                    k -= 1;
                }
            } else if (c == '#') {
                long long half = lengths[i] / 2;
                if (half > 0) k %= half;
            } else if (c == '%') {
                rev = !rev;
            }
            // '*' : no change to k or rev; conceptually the string was one
            // element longer just before this operation.
        }
        return '.';
    }
};
