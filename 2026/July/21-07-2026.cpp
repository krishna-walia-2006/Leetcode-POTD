// LeetCode 3499. Maximize Active Section with Trade I
// Daily challenge: 2026-07-21
//
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t = "1" + s + "1";
        int n = t.size();
        vector<pair<char,int>> runs;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && t[j] == t[i]) j++;
            runs.push_back({t[i], j - i});
            i = j;
        }
        int ones = count(s.begin(), s.end(), '1');
        int maxGain = 0;
        for (int k = 1; k + 1 < (int)runs.size(); k++) {
            if (runs[k].first == '1') {
                int gain = runs[k-1].second + runs[k+1].second;
                maxGain = max(maxGain, gain);
            }
        }
        return ones + maxGain;
    }
};
