// LeetCode 3069. Distribute Elements Into Two Arrays I
// Daily challenge: 2026-08-20
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1, arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for (int i = 2; i < (int)nums.size(); ++i) {
            if (arr1.back() > arr2.back()) arr1.push_back(nums[i]);
            else arr2.push_back(nums[i]);
        }
        vector<int> result = arr1;
        result.insert(result.end(), arr2.begin(), arr2.end());
        return result;
    }
};
