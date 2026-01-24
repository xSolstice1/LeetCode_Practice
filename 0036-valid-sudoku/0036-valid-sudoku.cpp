class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9], col[9][9], box[9][9];

        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (board[i][j] == '.') continue;
                char c = board[i][j] - '1';
                int boxInd = (i/3) * 3 + (j/3);

                if (row[i][c] || col[j][c] || box[boxInd][c]) return false;

                row[i][c] = true;
                col[j][c] = true;
                box[boxInd][c] = true;
            }
        }

        return true;
    }
};