// LeetCode 3116. Kth Smallest Amount With Single Denomination Combination
// Daily challenge: 2026-08-21
//
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        long long lo = 1, hi = 2e18;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            long long count = 0;
            for (int mask = 1; mask < (1 << n); mask++) {
                long long l = 1;
                bool overflow = false;
                int bits = __builtin_popcount(mask);
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        l = std::lcm(l, (long long)coins[i]);
                        if (l > mid) { overflow = true; break; }
                    }
                }
                if (overflow) continue;
                long long cnt = mid / l;
                if (bits % 2 == 1) count += cnt; else count -= cnt;
            }
            if (count < k) lo = mid + 1; else hi = mid;
        }
        return lo;
    }
};
