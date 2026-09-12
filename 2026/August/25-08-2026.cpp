// LeetCode 3718. Smallest Missing Multiple of K
// Daily challenge: 2026-08-25
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());
        for (long long i = 1; ; i++) {
            long long x = k * i;
            if (!s.count((int)x)) return (int)x;
        }
    }
};
