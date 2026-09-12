// LeetCode 2144. Minimum Cost of Buying Candies With Discount
// Daily challenge: 2026-06-01
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());
        int total = 0;
        for (int i = 0; i < (int)cost.size(); i++) {
            if (i % 3 != 2) total += cost[i];
        }
        return total;
    }
};
