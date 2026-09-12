// LeetCode 3121. Count the Number of Special Characters II
// Daily challenge: 2026-05-27

#include <string>
#include <vector>
#include <climits>
#include <cctype>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lastLower(26, -1), firstUpper(26, INT_MAX);
        vector<bool> seenLower(26, false), seenUpper(26, false);
        int n = word.size();
        for (int i = 0; i < n; i++) {
            char c = word[i];
            if (islower((unsigned char)c)) { lastLower[c-'a'] = i; seenLower[c-'a'] = true; }
            else { firstUpper[c-'A'] = min(firstUpper[c-'A'], i); seenUpper[c-'A'] = true; }
        }
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (seenLower[i] && seenUpper[i] && lastLower[i] < firstUpper[i]) count++;
        }
        return count;
    }
};
