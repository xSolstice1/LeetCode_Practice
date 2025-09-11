class Solution {
public:
    void backtrack(int n, vector<vector<string>>& res, vector<string>& board, vector<bool>& cols,
    vector<bool>& diag1, vector<bool>& diag2, int row) {
        if (row == n) res.push_back(board); //base case

        for (int i=0; i<n; i++) {
            if (cols[i] || diag1[row-i+n] || diag2[row+i]) {
                continue;
            }

            board[row][i] = 'Q';
            cols[i] = diag1[row-i+n] = diag2[row+i] = true; //set to occupied for column/diagonally
            backtrack(n,res,board,cols,diag1,diag2,row+1); //backtrack
            cols[i] = diag1[row-i+n] = diag2[row+i] = false; //reset
            board[row][i] = '.'; //reset
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n,string(n,'.')); //fill board with empty

        vector<bool> cols(n,false); //occupied cols

        vector<bool> diag1(2*n,false); //row-col+n

        //     c0   c1   c2   c3
        // r0  0  -1  -2  -3
        // r1  1   0  -1  -2
        // r2  2   1   0  -1
        // r3  3   2   1   0

        vector<bool> diag2(2*n,false); //row+col

        //     c0   c1   c2   c3
        // r0  0   1   2   3
        // r1  1   2   3   4
        // r2  2   3   4   5
        // r3  3   4   5   6

        backtrack(n,res,board,cols,diag1,diag2,0);

        return res;
    }
};