// LeetCode 3020. Find the Maximum Number of Elements in Subset
// Daily challenge: 2026-06-27
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> count;
        for (int num : nums) count[num]++;
        int max_len = 0;

        if (count.count(1)) {
            int ones = count[1];
            max_len = (ones % 2 == 0) ? ones - 1 : ones;
        }

        for (auto& p : count) {
            long long x = p.first;
            if (x == 1) continue;
            int current_len = 0;
            while (count.count(x) && count[x] >= 2) {
                current_len += 2;
                x = x * x;
            }
            if (count.count(x)) current_len += 1;
            else current_len -= 1;
            max_len = max(max_len, current_len);
        }
        return max_len;
    }
};
