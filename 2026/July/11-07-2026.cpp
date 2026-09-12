// LeetCode 2685. Count the Number of Complete Components
// Daily challenge: 2026-07-11
#include <vector>
#include <numeric>
#include <unordered_map>
#include <functional>
using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };
        for (auto& e : edges) {
            int a = find(e[0]), b = find(e[1]);
            if (a != b) parent[a] = b;
        }
        unordered_map<int,int> nodeCount, edgeCount;
        for (int i = 0; i < n; i++) nodeCount[find(i)]++;
        for (auto& e : edges) edgeCount[find(e[0])]++;

        int result = 0;
        for (auto& [root, cnt] : nodeCount) {
            long long need = (long long)cnt * (cnt - 1) / 2;
            if (edgeCount[root] == need) result++;
        }
        return result;
    }
};
