class Solution {
private:
    bool row[9][9] = {false}, col[9][9] = {false}, box[9][9] = {false};

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (board[i][j] == '.') continue;

                int ch = board[i][j] - '1';
                int k = (i/3)*3+(j/3);

                if (row[i][ch]||col[j][ch]||box[k][ch]) return false;

                row[i][ch]=col[j][ch]=box[k][ch]=true;
            }
        }  

        return true;
    }
};