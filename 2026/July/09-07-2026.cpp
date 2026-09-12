// LeetCode 3532. Path Existence Queries in a Graph I
// Daily challenge: 2026-07-09
//
#include <vector>
#include <numeric>
#include <functional>
using namespace std;

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };
        for (int i = 0; i + 1 < n; i++) {
            if (nums[i+1] - nums[i] <= maxDiff) {
                int a = find(i), b = find(i+1);
                if (a != b) parent[a] = b;
            }
        }
        vector<bool> ans;
        for (auto& q : queries) ans.push_back(find(q[0]) == find(q[1]));
        return ans;
    }
};
