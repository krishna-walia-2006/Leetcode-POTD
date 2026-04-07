class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        vector<pair<int, int>> r(n);
        for (int i = 0; i < n; ++i) {
            r[i] = {robots[i], distance[i]};
        }
        sort(r.begin(), r.end());
        sort(walls.begin(), walls.end());
        vector<vector<long long>> dp(n, vector<long long>(2, 0));
        auto countInRange = [&](long long L, long long R) -> int {
    if (L > R) return 0;
    auto it1 = lower_bound(walls.begin(), walls.end(), L);
    auto it2 = upper_bound(walls.begin(), walls.end(), R);
    // Use std::distance to distinguish it from the 'distance' vector
    return (int)std::distance(it1, it2); 
};

        long long p0 = r[0].first;
        long long d0 = r[0].second;
        long long next_p = (n > 1) ? r[1].first : 2e9 + 7;
        
        dp[0][0] = countInRange(p0 - d0, p0);
        dp[0][1] = countInRange(p0, min(p0 + d0, next_p));

        for (int i = 1; i < n; ++i) {
            long long cur_p = r[i].first;
            long long cur_d = r[i].second;
            long long prev_p = r[i-1].first;
            long long prev_d = r[i-1].second;
            long long next_p = (i + 1 < n) ? r[i+1].first : 2e9 + 7;

            long long limit_L = max(cur_p - cur_d, prev_p);
            long long limit_R_curr = min(cur_p + cur_d, next_p);
            long long limit_R_prev = min(prev_p + prev_d, cur_p);
            dp[i][0] = max(dp[i][0], dp[i-1][0] + countInRange(max(limit_L, prev_p + 1), cur_p));
            dp[i][0] = max(dp[i][0], dp[i-1][1] + countInRange(max(limit_L, limit_R_prev + 1), cur_p));
            dp[i][1] = max(dp[i][1], dp[i-1][0] + countInRange(cur_p, limit_R_curr));
            dp[i][1] = max(dp[i][1], dp[i-1][1] + countInRange(max(cur_p, limit_R_prev + 1), limit_R_curr));
        }

        return (int)max(dp[n-1][0], dp[n-1][1]);
    }
};
