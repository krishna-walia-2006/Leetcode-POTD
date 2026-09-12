// LeetCode 1967. Number of Strings That Appear as Substrings in Word
// Daily challenge: 2026-06-29
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for (const string& pattern : patterns) {
            if (word.find(pattern) != string::npos) count++;
        }
        return count;
    }
};
