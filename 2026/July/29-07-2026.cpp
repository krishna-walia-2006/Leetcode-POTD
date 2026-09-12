// LeetCode 3518. Smallest Palindromic Rearrangement II
// Daily challenge: 2026-07-29
//

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;

class Solution {
    static const ull CAP = (ull)4e18;

    ull nCr_capped(long long n, long long r) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);
        __int128 result = 1;
        for (long long i = 0; i < r; i++) {
            result = result * (n - i) / (i + 1);
            if (result > (__int128)CAP) return CAP;
        }
        return (ull)result;
    }

    ull multinomial_capped(vector<int>& cnt) {
        __int128 result = 1;
        long long remaining = 0;
        for (int i = 0; i < 26; i++) remaining += cnt[i];
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 0) continue;
            ull c = nCr_capped(remaining, cnt[i]);
            result = result * (__int128)c;
            if (result > (__int128)CAP) return CAP;
            remaining -= cnt[i];
        }
        return (ull)result;
    }

public:
    string smallestPalindrome(string s, long long k) {
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c-'a']++;
        int mid = -1;
        vector<int> half(26, 0);
        for (int i = 0; i < 26; i++) {
            half[i] = cnt[i] / 2;
            if (cnt[i] % 2) mid = i;
        }

        ull total = multinomial_capped(half);
        if ((ull)k > total) return "";

        long long remaining = 0;
        for (int i = 0; i < 26; i++) remaining += half[i];

        string result;
        for (long long pos = 0; pos < remaining; pos++) {
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0) continue;
                half[c]--;
                ull ways = multinomial_capped(half);
                if ((ull)k <= ways) {
                    result.push_back('a' + c);
                    break;
                } else {
                    k -= ways;
                    half[c]++;
                }
            }
        }
        string rev = result;
        reverse(rev.begin(), rev.end());
        string midStr = (mid == -1) ? "" : string(1, 'a' + mid);
        return result + midStr + rev;
    }
};
