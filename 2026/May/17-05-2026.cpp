// LeetCode 1306. Jump Game III
// Daily challenge: 2026-05-17
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start); visited[start] = true;
        while (!q.empty()) {
            int i = q.front(); q.pop();
            if (arr[i] == 0) return true;
            int nexts[2] = {i + arr[i], i - arr[i]};
            for (int ni : nexts) {
                if (ni >= 0 && ni < n && !visited[ni]) { visited[ni] = true; q.push(ni); }
            }
        }
        return false;
    }
};
