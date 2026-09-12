// LeetCode 3312. Sorted GCD Pair Queries
// Daily challenge: 2026-07-17
//
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int V = *max_element(nums.begin(), nums.end());
        vector<long long> freq(V + 1, 0);
        for (int x : nums) freq[x]++;

        vector<long long> cntMultiples(V + 1, 0);
        for (int d = 1; d <= V; d++)
            for (int m = d; m <= V; m += d) cntMultiples[d] += freq[m];

        vector<long long> exact(V + 1, 0);
        for (int d = V; d >= 1; d--) {
            long long c = cntMultiples[d];
            exact[d] = c * (c - 1) / 2;
            for (int m = 2 * d; m <= V; m += d) exact[d] -= exact[m];
        }

        vector<long long> prefix(V + 1, 0);
        for (int d = 1; d <= V; d++) prefix[d] = prefix[d-1] + exact[d];

        vector<int> ans;
        for (long long k : queries) {
            long long target = k + 1;
            int d = lower_bound(prefix.begin(), prefix.end(), target) - prefix.begin();
            ans.push_back(d);
        }
        return ans;
    }
};
