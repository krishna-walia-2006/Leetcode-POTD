// LeetCode 2161. Partition Array According to Given Pivot
// Daily challenge: 2026-06-08
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, equal, greater;
        for (int x : nums) {
            if (x < pivot) less.push_back(x);
            else if (x == pivot) equal.push_back(x);
            else greater.push_back(x);
        }
        less.insert(less.end(), equal.begin(), equal.end());
        less.insert(less.end(), greater.begin(), greater.end());
        return less;
    }
};
