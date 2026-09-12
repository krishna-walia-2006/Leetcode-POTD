// LeetCode 3501. Maximize Active Section with Trade II
// Daily challenge: 2026-07-22
//
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            string sub = s.substr(l, r - l + 1);
            string t = "1" + sub + "1";
            int n = t.size();
            vector<pair<char,int>> runs;
            int i = 0;
            while (i < n) {
                int j = i;
                while (j < n && t[j] == t[i]) j++;
                runs.push_back({t[i], j - i});
                i = j;
            }
            int ones = count(sub.begin(), sub.end(), '1');
            int maxGain = 0;
            for (int k = 1; k + 1 < (int)runs.size(); k++) {
                if (runs[k].first == '1') {
                    int gain = runs[k-1].second + runs[k+1].second;
                    maxGain = max(maxGain, gain);
                }
            }
            ans.push_back(ones + maxGain);
        }
        return ans;
    }
};
