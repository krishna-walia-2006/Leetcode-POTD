
#include <vector>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        vector<vector<int>> d(m, vector<int>(n, 0));
        int sx = 0, sy = 0, cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = classroom[i][j];
                if (c == 'S') { sx = i; sy = j; }
                else if (c == 'L') { d[i][j] = cnt; cnt++; }
            }
        }
        if (cnt == 0) return 0;
        int fullMask = (1 << cnt) - 1;

        vector<vector<vector<vector<bool>>>> vis(
            m, vector<vector<vector<bool>>>(
                n, vector<vector<bool>>(
                    energy + 1, vector<bool>(1 << cnt, false))));

        queue<tuple<int,int,int,int>> q;
        q.push({sx, sy, energy, fullMask});
        vis[sx][sy][energy][fullMask] = true;

        int dirs[5] = {-1, 0, 1, 0, -1};
        int ans = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int t = 0; t < sz; t++) {
                auto [i, j, curEnergy, mask] = q.front(); q.pop();
                if (mask == 0) return ans;
                if (curEnergy <= 0) continue;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dirs[k], nj = j + dirs[k+1];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && classroom[ni][nj] != 'X') {
                        int nextEnergy = (classroom[ni][nj] == 'R') ? energy : curEnergy - 1;
                        int nextMask = mask;
                        if (classroom[ni][nj] == 'L') nextMask &= ~(1 << d[ni][nj]);
                        if (!vis[ni][nj][nextEnergy][nextMask]) {
                            vis[ni][nj][nextEnergy][nextMask] = true;
                            q.push({ni, nj, nextEnergy, nextMask});
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
