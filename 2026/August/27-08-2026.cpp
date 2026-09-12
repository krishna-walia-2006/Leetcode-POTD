// LeetCode 3720. Lexicographically Smallest Permutation Greater Than Target
// Daily challenge: 2026-08-27
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        map<char,int> freq;
        for (char c : s) freq[c]++;

        string ans = "";
        for (int i = 0; i < n; i++) {
            map<char,int> cur = freq;
            bool possible = true;
            string prefix;
            for (int j = 0; j < i; j++) {
                char c = target[j];
                auto it = cur.find(c);
                if (it == cur.end() || it->second == 0) { possible = false; break; }
                it->second--;
                if (it->second == 0) cur.erase(it);
                prefix.push_back(c);
            }
            if (!possible) break; // longer prefixes can't work either

            auto it = cur.upper_bound(target[i]);
            if (it == cur.end()) continue;
            char pick = it->first;

            string res = prefix;
            res.push_back(pick);
            cur[pick]--;
            if (cur[pick] == 0) cur.erase(pick);
            for (auto& [ch, cnt] : cur) res.append(cnt, ch);

            if (ans == "" || res < ans) ans = res;
        }
        return ans;
    }
};
