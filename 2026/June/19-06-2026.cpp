// LeetCode 1732. Find the Highest Altitude
// Daily challenge: 2026-06-19
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int cur = 0, mx = 0;
        for (int g : gain) { cur += g; mx = max(mx, cur); }
        return mx;
    }
};
