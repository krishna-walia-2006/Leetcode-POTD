// LeetCode 1665. Minimum Initial Energy to Finish Tasks
// Daily challenge: 2026-05-12
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1]-a[0]) > (b[1]-b[0]);
        });
        long long energy = 0;
        for (auto& t : tasks) {
            if (energy < t[1]) energy = t[1];
            energy -= t[0];
        }
        return (int)energy;
    }
};
