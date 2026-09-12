// LeetCode 3514. Number of Unique XOR Triplets II
// Daily challenge: 2026-07-24
//
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen;
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                for (int k = j; k < n; k++)
                    seen.insert(nums[i] ^ nums[j] ^ nums[k]);
        return seen.size();
    }
};
