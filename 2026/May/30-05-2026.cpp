// LeetCode 3161. Block Placement Queries
// Daily challenge: 2026-05-30

#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<bool> res;
        set<int> obstacles;
        obstacles.insert(0);

        for (auto& q : queries) {
            if (q[0] == 1) {
                obstacles.insert(q[1]);
            } else {
                int x = q[1], sz = q[2];
                bool found = false;
                int prev = 0;
                for (int obs : obstacles) {
                    if (obs > x) break;
                    if (obs - prev >= sz) { found = true; break; }
                    prev = obs;
                }
                if (!found && x - prev >= sz) found = true;
                res.push_back(found);
            }
        }
        return res;
    }
};
