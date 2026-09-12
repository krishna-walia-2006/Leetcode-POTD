// LeetCode 3014. Minimum Number of Pushes to Type Word I
// Daily challenge: 2026-07-30
//

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> firstSeenOrder, freq;
        int order = 0;
        for (char c : word) {
            freq[c]++;
            if (!firstSeenOrder.count(c)) firstSeenOrder[c] = order++;
        }
        int total = 0;
        for (auto& [c, cnt] : freq) {
            int pos = firstSeenOrder[c];
            total += cnt * (pos / 8 + 1);
        }
        return total;
    }
};
