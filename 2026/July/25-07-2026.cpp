// LeetCode 3536. Maximum Product of Two Digits
// Daily challenge: 2026-07-25
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(int n) {
        vector<int> digits;
        while (n > 0) { digits.push_back(n % 10); n /= 10; }
        sort(digits.rbegin(), digits.rend());
        return digits[0] * digits[1];
    }
};
