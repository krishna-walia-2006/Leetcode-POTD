// LeetCode 1846. Maximum Element After Decreasing and Rearranging
// Daily challenge: 2026-06-28
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for (int i = 1; i < (int)arr.size(); i++) arr[i] = min(arr[i], arr[i-1] + 1);
        return arr.back();
    }
};
