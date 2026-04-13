class Solution {
    int memo[301][27];
    int getDist(int from, int to) {
        if (from == 26) return 0; 
        int x1 = from / 6, y1 = from % 6;
        int x2 = to / 6, y2 = to % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int solve(string& word, int idx, int otherFinger) {
        if (idx == word.length()) return 0;
        if (memo[idx][otherFinger] != -1) return memo[idx][otherFinger];
        int currChar = word[idx] - 'A';
        int prevChar = word[idx - 1] - 'A';
        int movePrev = getDist(prevChar, currChar) + solve(word, idx + 1, otherFinger);

        int moveOther = getDist(otherFinger, currChar) + solve(word, idx + 1, prevChar);

        return memo[idx][otherFinger] = min(movePrev, moveOther);
    }

public:
    int minimumDistance(string word) {

        for (int i = 0; i < 301; ++i)
            for (int j = 0; j < 27; ++j)
                memo[i][j] = -1;
        return solve(word, 1, 26);
    }
};
