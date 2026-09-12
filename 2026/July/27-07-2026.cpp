// LeetCode 1464. Maximum Product of Two Elements in an Array
// Daily challenge: 2026-07-27
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a = INT_MIN, b = INT_MIN;
        for (int x : nums) {
            if (x > a) { b = a; a = x; }
            else if (x > b) b = x;
        }
        return (a - 1) * (b - 1);
    }
};
