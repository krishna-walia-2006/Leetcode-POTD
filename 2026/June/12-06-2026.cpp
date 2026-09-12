// LeetCode 3559. Number of Ways to Assign Edge Weights II
// Daily challenge: 2026-06-12
//

#include <vector>
#include <queue>
using namespace std;

class Solution {
    static const int LOG = 18;
    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<int> depth;
    const long long MOD = 1e9 + 7;

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for (int j = 0; j < LOG; j++) if ((diff >> j) & 1) u = up[j][u];
        if (u == v) return u;
        for (int j = LOG-1; j >= 0; j--) {
            if (up[j][u] != up[j][v]) { u = up[j][u]; v = up[j][v]; }
        }
        return up[0][u];
    }

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) res = res * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }
        return res;
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        adj.assign(n + 1, {});
        for (auto& e : edges) { adj[e[0]].push_back(e[1]); adj[e[1]].push_back(e[0]); }

        depth.assign(n + 1, -1);
        up.assign(LOG, vector<int>(n + 1, 1));
        queue<int> q;
        q.push(1); depth[1] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (depth[v] == -1) {
                    depth[v] = depth[u] + 1;
                    up[0][v] = u;
                    q.push(v);
                }
            }
        }
        for (int j = 1; j < LOG; j++)
            for (int v = 1; v <= n; v++) up[j][v] = up[j-1][up[j-1][v]];

        vector<int> ans;
        for (auto& query : queries) {
            int u = query[0], v = query[1];
            int a = lca(u, v);
            int dist = depth[u] + depth[v] - 2 * depth[a];
            ans.push_back(dist == 0 ? 0 : (int)power(2, dist - 1));
        }
        return ans;
    }
};
