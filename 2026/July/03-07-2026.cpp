// LeetCode 3620. Network Recovery Pathways
// Daily challenge: 2026-07-03
//

#include <vector>
#include <climits>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    int maxScore(int n, vector<vector<int>>& edges, vector<bool>& online, int k) {
        int hi = 0;
        for (auto& e : edges) hi = max(hi, e[2]);
        int lo = 1, ans = -1;

        auto feasible = [&](int mid) -> bool {
            vector<vector<pair<int,int>>> g(n);
            for (auto& e : edges) {
                int u = e[0], v = e[1], c = e[2];
                if (c < mid) continue;
                if (u != 0 && !online[u]) continue;
                if (v != n - 1 && !online[v]) continue;
                g[u].push_back({v, c});
            }
            vector<int> state(n, 0);
            vector<int> order;
            order.reserve(n);
            function<void(int)> dfs = [&](int u) {
                state[u] = 1;
                for (auto& [v, c] : g[u]) if (state[v] == 0) dfs(v);
                state[u] = 2;
                order.push_back(u);
            };
            for (int i = 0; i < n; i++) if (state[i] == 0) dfs(i);
            reverse(order.begin(), order.end());

            vector<long long> dist(n, LLONG_MAX);
            dist[0] = 0;
            for (int u : order) {
                if (dist[u] == LLONG_MAX) continue;
                for (auto& [v, c] : g[u]) {
                    if (dist[u] + c < dist[v]) dist[v] = dist[u] + c;
                }
            }
            return dist[n-1] != LLONG_MAX && dist[n-1] <= k;
        };

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (feasible(mid)) { ans = mid; lo = mid + 1; }
            else hi = mid - 1;
        }
        return ans;
    }
};
