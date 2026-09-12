// LeetCode 3635. Earliest Finish Time for Land and Water Rides II
// Daily challenge: 2026-06-03
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                            vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();
        int minLandFinish = INT_MAX, minWaterFinish = INT_MAX;
        for (int i = 0; i < n; i++) minLandFinish = min(minLandFinish, landStartTime[i] + landDuration[i]);
        for (int j = 0; j < m; j++) minWaterFinish = min(minWaterFinish, waterStartTime[j] + waterDuration[j]);

        int ans = INT_MAX;
        for (int j = 0; j < m; j++) {
            int start = max(minLandFinish, waterStartTime[j]);
            ans = min(ans, start + waterDuration[j]);
        }
        for (int i = 0; i < n; i++) {
            int start = max(minWaterFinish, landStartTime[i]);
            ans = min(ans, start + landDuration[i]);
        }
        return ans;
    }
};
