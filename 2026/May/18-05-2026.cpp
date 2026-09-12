// LeetCode 1345. Jump Game IV
// Daily challenge: 2026-05-18
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;
        unordered_map<int, vector<int>> idxByVal;
        for (int i = 0; i < n; i++) idxByVal[arr[i]].push_back(i);

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0); visited[0] = true;
        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int k = 0; k < sz; k++) {
                int i = q.front(); q.pop();
                if (i == n - 1) return steps;
                if (i+1 < n && !visited[i+1]) { visited[i+1] = true; q.push(i+1); }
                if (i-1 >= 0 && !visited[i-1]) { visited[i-1] = true; q.push(i-1); }
                auto it = idxByVal.find(arr[i]);
                if (it != idxByVal.end()) {
                    for (int j : it->second) {
                        if (!visited[j]) { visited[j] = true; q.push(j); }
                    }
                    idxByVal.erase(it);
                }
            }
            steps++;
        }
        return -1;
    }
};
