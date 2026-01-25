class Solution {
private:
    bool row[9][9] = {false}, col[9][9] = {false}, box[9][9] = {false};
    vector<pair<int,int>> emptyCells;

    bool backtrack(vector<vector<char>>& board, int step) {
        if (step == emptyCells.size()) return true;

        auto [r,c] = emptyCells[step];
        int k = (r/3)*3+(c/3);

        for (int i=0; i<9; i++) {
            if (!row[r][i]&&!col[c][i]&&!box[k][i]) {
                board[r][c] = i+'1';
                row[r][i]=col[c][i]=box[k][i]=true;

                if (backtrack(board,step+1)) return true;

                board[r][c] = '.';
                row[r][i]=col[c][i]=box[k][i]=false;
            }
        }

        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (board[i][j] == '.') {
                    emptyCells.push_back({i,j});
                } else {
                    int ch = board[i][j] - '1';
                    int k = (i/3)*3+(j/3);

                    row[i][ch]=col[j][ch]=box[k][ch]=true;
                }
            }
        }

        backtrack(board,0);
    }
};