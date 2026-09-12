// LeetCode 1752. Check if Array Is Sorted and Rotated
// Daily challenge: 2026-05-23
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), count = 0;
        for (int i = 0; i < n; i++) if (nums[i] > nums[(i+1) % n]) count++;
        return count <= 1;
    }
};
