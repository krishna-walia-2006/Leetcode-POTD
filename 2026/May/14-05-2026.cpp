// LeetCode 2784. Check if Array Is Good
// Daily challenge: 2026-05-14
#include <vector>
using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;
        vector<int> cnt(n + 2, 0);
        for (int x : nums) {
            if (x < 0 || x > n) return false;
            cnt[x]++;
        }
        for (int i = 1; i < n; i++) if (cnt[i] != 1) return false;
        return cnt[n] == 2;
    }
};
