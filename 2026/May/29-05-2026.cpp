// LeetCode 3300. Minimum Element After Replacement With Digit Sum
// Daily challenge: 2026-05-29
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minElement(vector<int>& nums) {
        int mn = INT_MAX;
        for (int x : nums) {
            int s = 0;
            while (x > 0) { s += x % 10; x /= 10; }
            mn = min(mn, s);
        }
        return mn;
    }
};
