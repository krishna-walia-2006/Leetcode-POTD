// LeetCode 3345. Smallest Divisible Digit Product I
// Daily challenge: 2026-08-06
class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int prod = 1;
            int temp = n;
            while (temp > 0) {
                prod *= (temp % 10);
                temp /= 10;
            }
            if (prod % t == 0) return n;
            n++;
        }
    }
};
