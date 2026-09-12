// LeetCode 3534. Path Existence Queries in a Graph II
// Daily challenge: 2026-07-10
//

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> reach(n);
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (j < i) j = i;
            while (j + 1 < n && nums[j+1] - nums[i] <= maxDiff) j++;
            reach[i] = j;
        }

        vector<int> ans;
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            if (u > v) swap(u, v);
            if (u == v) { ans.push_back(0); continue; }

            int steps = 0, curEnd = u, farthest = u, i = u;
            int result = -1;
            while (i <= curEnd) {
                farthest = max(farthest, reach[i]);
                if (i == curEnd) {
                    steps++;
                    if (farthest >= v) { result = steps; break; }
                    if (farthest == curEnd) break; // stuck, cannot progress further
                    curEnd = farthest;
                }
                i++;
            }
            ans.push_back(result);
        }
        return ans;
    }
};
