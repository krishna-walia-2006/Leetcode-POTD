// LeetCode 1358. Number of Substrings Containing All Three Characters
// Daily challenge: 2026-06-30
#include <string>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int counts[3] = {0};
        int res = 0, i = 0;
        for (int j = 0; j < (int)s.length(); ++j) {
            counts[s[j] - 'a']++;
            while (counts[0] > 0 && counts[1] > 0 && counts[2] > 0) {
                res += s.length() - j;
                counts[s[i] - 'a']--;
                i++;
            }
        }
        return res;
    }
};
