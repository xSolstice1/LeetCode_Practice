class Solution {
public:
    bool isValid(vector<vector<char>>& board, char ch, int r, int c) {
        for (int i=0; i<board.size(); i++) {
            int boxR = (r/3) * 3 + (i/3);
            int boxC = (c/3) * 3 + (i%3);

            if (board[r][i]==ch||board[i][c]==ch||board[boxR][boxC]==ch) return false;
        }

        return true;
    }
    bool backtrack(vector<vector<char>>& board) {
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (board[i][j]=='.') {
                    for (int ch='1';ch<='9';ch++) {
                        if (isValid(board,ch,i,j)) {
                            board[i][j]=ch;
                            if (backtrack(board)) return true;
                            board[i][j]='.';
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