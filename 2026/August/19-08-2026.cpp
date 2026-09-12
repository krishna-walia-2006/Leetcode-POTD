// LeetCode 1386. Cinema Seat Allocation
// Daily challenge: 2026-08-19
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,int> rowMask;
        for (auto& s : reservedSeats) {
            int r = s[0], c = s[1];
            if (c >= 2 && c <= 9) rowMask[r] |= (1 << (c - 2));
        }
        long long total = (long long)(n - (int)rowMask.size()) * 2;
        const int leftMask = 0b00001111;
        const int midMask  = 0b00111100;
        const int rightMask = 0b11110000;
        for (auto& [r, m] : rowMask) {
            if ((m & leftMask) == 0 && (m & rightMask) == 0) total += 2;
            else if ((m & leftMask) == 0 || (m & midMask) == 0 || (m & rightMask) == 0) total += 1;
        }
        return (int)total;
    }
};
