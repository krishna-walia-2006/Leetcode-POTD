// LeetCode 1189. Maximum Number of Balloons
// Daily challenge: 2026-06-22
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> count;
        for (char c : text) count[c]++;
        return min({count['b'], count['a'], count['l'] / 2, count['o'] / 2, count['n']});
    }
};
