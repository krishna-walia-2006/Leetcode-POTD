

#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return intervals[a][1] < intervals[b][1];
        });

        vector<long long> ends(n);
        for (int i = 0; i < n; i++) ends[i] = intervals[idx[i]][1];

        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            long long start = intervals[idx[i]][0];
            int lo = 0, hi = n;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (ends[mid] < start) lo = mid + 1; else hi = mid;
            }
            p[i] = lo;
        }

        vector<vector<long long>> dpWeight(n + 1, vector<long long>(5, 0));
        vector<vector<vector<int>>> dpList(n + 1, vector<vector<int>>(5));

        for (int i = 1; i <= n; i++) {
            int curOrig = idx[i-1];
            long long w = intervals[curOrig][2];
            for (int j = 1; j <= 4; j++) {
                long long bestW = dpWeight[i-1][j];
                vector<int> bestList = dpList[i-1][j];

                long long takeW = dpWeight[p[i-1]][j-1] + w;
                vector<int> takeList = dpList[p[i-1]][j-1];
                takeList.push_back(curOrig);
                sort(takeList.begin(), takeList.end());

                if (takeW > bestW || (takeW == bestW && takeList < bestList)) {
                    bestW = takeW; bestList = takeList;
                }
                dpWeight[i][j] = bestW;
                dpList[i][j] = bestList;
            }
        }
        return dpList[n][4];
    }
};
