class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> st;

        for (auto &obs : obstacles) {
            st.insert(to_string(obs[0]) + "_" + to_string(obs[1]));
        }

        int x = 0, y = 0;
        int maxDist = 0;

        pair<int,int> dir = {0, 1};
        for (int cmd : commands) {

            if (cmd == -2) {
                dir = {-dir.second, dir.first};
            }
            else if (cmd == -1) {
                dir = {dir.second, -dir.first};
            }
            else {
                for (int step = 0; step < cmd; step++) {
                    int nx = x + dir.first;
                    int ny = y + dir.second;
                    string key = to_string(nx) + "_" + to_string(ny);
                    if (st.count(key)) break;
                    x = nx;
                    y = ny;
                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }

        return maxDist;
    }
};
