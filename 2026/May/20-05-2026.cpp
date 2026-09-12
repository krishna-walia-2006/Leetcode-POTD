// LeetCode 2657. Find the Prefix Common Array of Two Arrays
// Daily challenge: 2026-05-20
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> C(n);
        vector<int> count(n + 1, 0);
        int common = 0;
        for (int i = 0; i < n; ++i) {
            if (++count[A[i]] == 2) common++;
            if (++count[B[i]] == 2) common++;
            C[i] = common;
        }
        return C;
    }
};
