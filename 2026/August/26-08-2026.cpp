// LeetCode 2904. Shortest and Lexicographically Smallest Beautiful String
// Daily challenge: 2026-08-26
#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        // Pass 1: shrinking window to find the minimal beautiful length.
        int left = 0, ones = 0, minLen = INT_MAX;
        for (int right = 0; right < n; right++) {
            if (s[right] == '1') ones++;
            while (ones > k) {
                if (s[left] == '1') ones--;
                left++;
            }
            while (ones == k) {
                minLen = min(minLen, right - left + 1);
                if (s[left] == '1') ones--;
                left++;
            }
        }
        if (minLen == INT_MAX) return "";

        // Pass 2: scan all windows of that length, keep the lexicographically smallest.
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + (s[i] - '0');

        string ans = "";
        for (int i = 0; i + minLen <= n; i++) {
            if (prefix[i + minLen] - prefix[i] == k) {
                string cand = s.substr(i, minLen);
                if (ans == "" || cand < ans) ans = cand;
            }
        }
        return ans;
    }
};
