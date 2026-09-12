// LeetCode 1081. Smallest Subsequence of Distinct Characters
// Daily challenge: 2026-07-19
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastIdx(26, -1);
        for (int i = 0; i < (int)s.size(); i++) lastIdx[s[i]-'a'] = i;
        vector<bool> inStack(26, false);
        string stack;
        for (int i = 0; i < (int)s.size(); i++) {
            char c = s[i];
            if (inStack[c-'a']) continue;
            while (!stack.empty() && stack.back() > c && lastIdx[stack.back()-'a'] > i) {
                inStack[stack.back()-'a'] = false;
                stack.pop_back();
            }
            stack.push_back(c);
            inStack[c-'a'] = true;
        }
        return stack;
    }
};
