class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i=0; i<board.size(); i++) {
            int boxRow = (row/3) * 3 + (i/3);
            int boxCol = (col/3) * 3 + (i%3);

            if (board[row][i] == c || board[i][col] == c || board[boxRow][boxCol] == c) return false;
        }

        return true;
    }
    bool backtrack(vector<vector<char>>& board) {
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (board[i][j] == '.') {
                    for (char c='1';c<='9';c++) {
                        if (isValid(board,i,j,c)) {
                            board[i][j] = c;
                            if (backtrack(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};