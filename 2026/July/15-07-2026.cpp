// LeetCode 3658. GCD of Odd and Even Sums
// Daily challenge: 2026-07-15
#include <numeric>
using namespace std;

class Solution {
public:
    long long gcdOfOddEvenSums(int n) {
        long long oddCount = (n + 1) / 2;
        long long sumOdd = oddCount * oddCount;          // 1+3+5+...  (k terms) = k^2
        long long sumTotal = (long long)n * (n + 1) / 2;
        long long sumEven = sumTotal - sumOdd;
        return gcd(sumOdd, sumEven);
    }
};
