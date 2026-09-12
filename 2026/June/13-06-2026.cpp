// LeetCode 3838. Weighted Word Mapping
// Daily challenge: 2026-06-13
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for (auto& w : words) {
            int s = 0;
            for (char c : w) s += weights[c-'a'];
            s %= 26;
            ans.push_back('a' + (25 - s));
        }
        return ans;
    }
};
