// LeetCode 1331. Rank Transform of an Array
// Daily challenge: 2026-07-12
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted_arr = arr;
        sort(sorted_arr.begin(), sorted_arr.end());
        unordered_map<int,int> rank;
        int r = 1;
        for (int x : sorted_arr) if (!rank.count(x)) rank[x] = r++;
        vector<int> result;
        for (int x : arr) result.push_back(rank[x]);
        return result;
    }
};
