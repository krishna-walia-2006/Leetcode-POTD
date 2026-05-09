class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m=boxGrid.size(),n=boxGrid[0].size();
        vector<vector<char>> rotated(n,vector<char> (m,'.'));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                rotated[i][j]=boxGrid[m-j-1][i];
                cout<<rotated[i][j];
            }
            cout<<endl;
        }

        for(int col=0;col<m;col++) {
            int spaceRow=n-1;
            for(int row=n-1;row>=0;row--) {
                if(rotated[row][col]=='*') {
                    spaceRow=row-1;
                    continue;
                }
                else if(rotated[row][col]=='#') {
                    rotated[row][col]='.';
                    rotated[spaceRow][col]='#';
                    spaceRow--;
                }
            }
        }
        return rotated;
    }
};
