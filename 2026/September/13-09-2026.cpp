

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;

        
        for (int row = -(n - 1); row < n; row++) {
            for (int col = -(n - 1); col < n; col++) {

                int curr = 0;

                
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {

                        int r = i + row;
                        int c = j + col;

                        if (r >= 0 && r < n && c >= 0 && c < n) {
                            if (img1[i][j] == 1 && img2[r][c] == 1) {
                                curr++;
                            }
                        }
                    }
                }

                ans = max(ans, curr);
            }
        }

        return ans;
    }
};