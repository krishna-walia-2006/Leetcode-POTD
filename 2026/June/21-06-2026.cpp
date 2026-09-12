// LeetCode 1833. Maximum Ice Cream Bars
// Daily challenge: 2026-06-21
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int count = 0;
        for (int c : costs) {
            if (coins >= c) { coins -= c; count++; }
            else break;
        }
        return count;
    }
};
