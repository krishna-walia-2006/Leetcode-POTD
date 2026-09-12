// LeetCode 1914. Cyclically Rotating a Grid
// Daily challenge: 2026-05-09
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int layers = min(m, n) / 2;
        for (int l = 0; l < layers; l++) {
            int top = l, bottom = m-1-l, left = l, right = n-1-l;
            vector<int> elems;
            for (int j = left; j <= right; j++) elems.push_back(grid[top][j]);
            for (int i = top+1; i <= bottom; i++) elems.push_back(grid[i][right]);
            for (int j = right-1; j >= left; j--) elems.push_back(grid[bottom][j]);
            for (int i = bottom-1; i > top; i--) elems.push_back(grid[i][left]);

            int sz = elems.size();
            int shift = k % sz;
            vector<int> rotated(sz);
            for (int idx = 0; idx < sz; idx++) rotated[idx] = elems[(idx + shift) % sz];

            int pos = 0;
            for (int j = left; j <= right; j++) grid[top][j] = rotated[pos++];
            for (int i = top+1; i <= bottom; i++) grid[i][right] = rotated[pos++];
            for (int j = right-1; j >= left; j--) grid[bottom][j] = rotated[pos++];
            for (int i = bottom-1; i > top; i--) grid[i][left] = rotated[pos++];
        }
        return grid;
    }
};
