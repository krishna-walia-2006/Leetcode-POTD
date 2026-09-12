// LeetCode 3310. Remove Methods From Project
// Daily challenge: 2026-08-05
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (auto& e : invocations) adj[e[0]].push_back(e[1]);

        vector<bool> suspicious(n, false);
        queue<int> q;
        q.push(k);
        suspicious[k] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (!suspicious[v]) {
                    suspicious[v] = true;
                    q.push(v);
                }
            }
        }

        // If any safe method directly calls a suspicious method, nothing can be removed.
        for (auto& e : invocations) {
            if (!suspicious[e[0]] && suspicious[e[1]]) {
                vector<int> all;
                for (int i = 0; i < n; ++i) all.push_back(i);
                return all;
            }
        }

        vector<int> result;
        for (int i = 0; i < n; ++i) if (!suspicious[i]) result.push_back(i);
        return result;
    }
};
