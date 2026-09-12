// LeetCode 3629. Minimum Jumps to Reach End via Prime Teleportation
// Daily challenge: 2026-05-08
//
// 
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> spf(mx + 1, 0);
        for (int i = 2; i <= mx; i++) {
            if (spf[i] == 0) {
                for (int j = i; j <= mx; j += i) if (spf[j] == 0) spf[j] = i;
            }
        }
        unordered_map<int, vector<int>> buckets;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            while (x > 1) {
                int p = spf[x];
                buckets[p].push_back(i);
                while (x % p == 0) x /= p;
            }
        }

        vector<int> dist(n, -1);
        queue<int> q;
        dist[0] = 0; q.push(0);
        while (!q.empty()) {
            int i = q.front(); q.pop();
            if (i == n - 1) return dist[i];
            if (i + 1 < n && dist[i+1] == -1) { dist[i+1] = dist[i] + 1; q.push(i+1); }
            if (i - 1 >= 0 && dist[i-1] == -1) { dist[i-1] = dist[i] + 1; q.push(i-1); }
            int x = nums[i];
            while (x > 1) {
                int p = spf[x];
                auto it = buckets.find(p);
                if (it != buckets.end()) {
                    for (int j : it->second) {
                        if (dist[j] == -1) { dist[j] = dist[i] + 1; q.push(j); }
                    }
                    buckets.erase(it);
                }
                while (x % p == 0) x /= p;
            }
        }
        return dist[n-1];
    }
};
