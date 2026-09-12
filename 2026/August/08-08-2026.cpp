// LeetCode 3302. Find the Lexicographically Smallest Valid Sequence
// Daily challenge: 2026-08-08
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> suff(n + 1, 0);
        int j = m - 1;
        for (int i = n - 1; i >= 0; --i) {
            if (j >= 0 && word1[i] == word2[j]) j--;
            suff[i] = m - 1 - j;
        }
        vector<int> ans;
        j = 0;
        bool changed = false;
        for (int i = 0; i < n && j < m; ++i) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            } else if (!changed && suff[i + 1] >= m - 1 - j) {
                changed = true;
                ans.push_back(i);
                j++;
            }
        }
        return j == m ? ans : vector<int>();
    }
};
