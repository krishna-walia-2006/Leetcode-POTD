class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if(rows==1) return encodedText;
        string ans="";
        int l=encodedText.size();
        int columns = l/rows;
        for(int col=0;col<columns;col++) {
            for(int j=col;j<l;j+=(columns+1)) {
                ans+=encodedText[j];
            } 
        }
        while(!ans.empty() && ans.back()==' ') ans.pop_back();
        return ans;
    }
};
