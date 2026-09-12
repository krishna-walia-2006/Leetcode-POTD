// LeetCode 2553. Separate the Digits in an Array
// Daily challenge: 2026-05-11
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (int x : nums) {
            string s = to_string(x);
            for (char c : s) ans.push_back(c - '0');
        }
        return ans;
    }
};
