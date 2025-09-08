class Solution {
private:
    //helper method to check for valid inserts
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i=0; i<board.size(); i++) {
            //compute the row and column of the ith index in the 3x3 box
            int boxRow = (row/3) * 3 + (i/3);
            int boxCol = (col/3) * 3 + (i%3);

            //if char to be inserted found in row,col or box, return false
            if (board[row][i] == c || board[i][col] == c || board[boxRow][boxCol] == c) {
                return false;
            }
        }

        return true;
    }

    //backtrack
    bool backtrack(vector<vector<char>>& board) {
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board.size(); j++) {
                if (board[i][j] == '.') { //check for empty cells
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board,i,j,c)) {
                            board[i][j] = c; //set cell to c if valid insertion
                            if (backtrack(board)) return true;
                            board[i][j] = '.'; //backtrack/reset cell
                        }
                    }
                    return false; //return false if no possible combination found
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};