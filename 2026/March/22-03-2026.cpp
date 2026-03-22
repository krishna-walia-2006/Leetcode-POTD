class Solution {
    void rotate90Deg(vector<vector<int>>& mat,int n) {
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                swap(mat[i][j],mat[j][i]);
            }
        }
        for(int i=0;i<n;i++) {
            reverse(mat[i].begin(),mat[i].end());
        }
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=mat.size();
        for(int c=1;c<=4;c++) {
            bool flag=true;
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if(mat[i][j]!=target[i][j]){
                        flag=false;
                        break;
                    }
                }
                if(!flag) break;
            }
            if(flag) return true;
            rotate90Deg(mat,n);
        }
        return false;
    }
};
