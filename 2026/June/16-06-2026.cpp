// LeetCode 3612. Process String with Special Operations I
// Daily challenge: 2026-06-16
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

class Solution {
public:
    string processStr(string s) {
        string result;
        for (char c : s) {
            if (islower((unsigned char)c)) result.push_back(c);
            else if (c == '*') { if (!result.empty()) result.pop_back(); }
            else if (c == '#') result += result;
            else if (c == '%') reverse(result.begin(), result.end());
        }
        return result;
    }
};
