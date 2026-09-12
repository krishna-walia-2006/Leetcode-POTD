// LeetCode 3731. Find Missing Elements
// Daily challenge: 2026-08-04
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> missing;
        for (int i = minVal; i <= maxVal; ++i) {
            if (!s.count(i)) missing.push_back(i);
        }
        return missing;
    }
};
