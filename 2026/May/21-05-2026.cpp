// LeetCode 3043. Find the Length of the Longest Common Prefix
// Daily challenge: 2026-05-21
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<long long> prefixes;
        for (int x : arr1) {
            long long val = x;
            while (val > 0) { prefixes.insert(val); val /= 10; }
        }
        int ans = 0;
        for (int x : arr2) {
            long long val = x;
            while (val > 0) {
                if (prefixes.count(val)) { ans = max(ans, (int)to_string(val).size()); break; }
                val /= 10;
            }
        }
        return ans;
    }
};
