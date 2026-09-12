// LeetCode 796. Rotate String
// Daily challenge: 2026-05-03
#include <string>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;
        string doubleS = s + s;
        return doubleS.find(goal) != string::npos;
    }
};
