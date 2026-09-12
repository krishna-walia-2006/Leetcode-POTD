// LeetCode 3517. Smallest Palindromic Rearrangement I
// Daily challenge: 2026-07-28
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c-'a']++;
        string half, mid;
        for (int i = 0; i < 26; i++) {
            half += string(cnt[i] / 2, 'a' + i);
            if (cnt[i] % 2) mid = string(1, 'a' + i);
        }
        string rev = half;
        reverse(rev.begin(), rev.end());
        return half + mid + rev;
    }
};
