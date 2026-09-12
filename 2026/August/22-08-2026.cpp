// LeetCode 3622. Check Divisibility by Digit Sum and Product
// Daily challenge: 2026-08-22
class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, product = 1;
        int temp = n;
        while (temp > 0) {
            int d = temp % 10;
            sum += d;
            product *= d;
            temp /= 10;
        }
        return (n % sum == 0) && (n % product == 0);
    }
};
