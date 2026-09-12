// LeetCode 3016. Minimum Number of Pushes to Type Word II
// Daily challenge: 2026-07-31
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> count(26, 0);
        for (char c : word) count[c - 'a']++;
        sort(count.rbegin(), count.rend());
        int totalPushes = 0;
        for (int i = 0; i < 26; ++i) {
            if (count[i] == 0) break;
            totalPushes += count[i] * ((i / 8) + 1);
        }
        return totalPushes;
    }
};
