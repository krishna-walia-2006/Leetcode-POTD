// LeetCode 1861. Rotating the Box
// Daily challenge: 2026-05-06
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        for (int i = 0; i < m; i++) {
            int writePos = n - 1;
            for (int j = n - 1; j >= 0; j--) {
                if (box[i][j] == '*') {
                    writePos = j - 1;
                } else if (box[i][j] == '#') {
                    box[i][j] = '.';
                    box[i][writePos] = '#';
                    writePos--;
                }
            }
        }
        vector<vector<char>> res(n, vector<char>(m));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                res[j][m-1-i] = box[i][j];
        return res;
    }
};
