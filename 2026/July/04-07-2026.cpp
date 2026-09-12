// LeetCode 2492. Minimum Score of a Path Between Two Cities
// Daily challenge: 2026-07-04
#include <vector>
#include <numeric>
#include <climits>
#include <functional>
using namespace std;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> parent(n + 1);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };
        for (auto& r : roads) {
            int a = find(r[0]), b = find(r[1]);
            if (a != b) parent[a] = b;
        }
        vector<int> minEdge(n + 1, INT_MAX);
        for (auto& r : roads) {
            int root = find(r[0]);
            minEdge[root] = min(minEdge[root], r[2]);
        }
        return minEdge[find(1)];
    }
};
