// LeetCode 3702. Longest Subsequence With Non-Zero Bitwise XOR
// Daily challenge: 2026-08-15
//
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXor = 0;
        bool hasNonZero = false;
        for (int x : nums) {
            totalXor ^= x;
            if (x != 0) hasNonZero = true;
        }
        int n = nums.size();
        if (totalXor != 0) return n;
        if (!hasNonZero) return 0;
        return n - 1;
    }
};
