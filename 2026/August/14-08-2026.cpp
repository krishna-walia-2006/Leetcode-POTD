// LeetCode 3090. Maximum Length Substring With Two Occurrences
// Daily challenge: 2026-08-14
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> cnt;
        int left = 0, maxLen = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            cnt[s[right]]++;
            while (cnt[s[right]] > 2) {
                cnt[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
