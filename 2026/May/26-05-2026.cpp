// LeetCode 3120. Count the Number of Special Characters I
// Daily challenge: 2026-05-26
#include <string>
#include <vector>
#include <cctype>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> lower(26, false), upper(26, false);
        for (char c : word) {
            if (islower((unsigned char)c)) lower[c-'a'] = true;
            else upper[c-'A'] = true;
        }
        int count = 0;
        for (int i = 0; i < 26; i++) if (lower[i] && upper[i]) count++;
        return count;
    }
};
