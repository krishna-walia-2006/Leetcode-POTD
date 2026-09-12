// LeetCode 3734. Lexicographically Smallest Palindromic Permutation Greater Than Target
// Daily challenge: 2026-08-28
//

#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    string smallestPalindrome(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        int oddCount = 0, oddChar = -1;
        for (int i = 0; i < 26; i++) if (cnt[i] % 2) { oddCount++; oddChar = i; }
        if ((n % 2 == 0 && oddCount != 0) || (n % 2 == 1 && oddCount != 1)) return "";

        int h = n / 2;
        map<char,int> half;
        for (int i = 0; i < 26; i++) if (cnt[i] / 2 > 0) half['a' + i] = cnt[i] / 2;
        char midChar = (n % 2 == 1) ? (char)('a' + oddChar) : 0;

        string best = "";
        auto consider = [&](const string& P) {
            if (P > target && (best == "" || P < best)) best = P;
        };

        // Case A: diverge at some position i within the first half.
        for (int i = 0; i < h; i++) {
            map<char,int> cur = half;
            bool ok = true;
            string prefix;
            for (int j = 0; j < i; j++) {
                char c = target[j];
                auto it = cur.find(c);
                if (it == cur.end() || it->second == 0) { ok = false; break; }
                it->second--;
                if (it->second == 0) cur.erase(it);
                prefix.push_back(c);
            }
            if (!ok) break;

            auto it = cur.upper_bound(target[i]);
            if (it == cur.end()) continue;
            char pick = it->first;

            string firstHalf = prefix;
            firstHalf.push_back(pick);
            cur[pick]--;
            if (cur[pick] == 0) cur.erase(pick);
            for (auto& [ch, c2] : cur) firstHalf.append(c2, ch);

            string rev = firstHalf;
            reverse(rev.begin(), rev.end());
            string P = firstHalf;
            if (midChar) P.push_back(midChar);
            P += rev;
            consider(P);
        }

        // Case B: first half matches target's prefix exactly; resolve via
        // the middle character and mirrored second half.
        {
            map<char,int> cur = half;
            bool ok = true;
            for (int j = 0; j < h; j++) {
                char c = target[j];
                auto it = cur.find(c);
                if (it == cur.end() || it->second == 0) { ok = false; break; }
                it->second--;
                if (it->second == 0) cur.erase(it);
            }
            if (ok && cur.empty()) {
                string firstHalf = target.substr(0, h);
                string rev = firstHalf;
                reverse(rev.begin(), rev.end());
                string P = firstHalf;
                if (midChar) P.push_back(midChar);
                P += rev;
                consider(P);
            }
        }

        return best;
    }
};
