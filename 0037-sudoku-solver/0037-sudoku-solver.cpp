class Solution {
private:
    bool row[9][9] = {false};
    bool col[9][9] = {false};
    bool box[9][9] = {false};
    vector<pair<int,int>> emptyCells;
public:
    // method 1: a little slow
    // bool isValid(vector<vector<char>>& board, char ch, int r, int c) {
    //     for (int i=0; i<board.size(); i++) {
    //         int boxR = (r/3) * 3 + (i/3);
    //         int boxC = (c/3) * 3 + (i%3);

    //         if (board[r][i]==ch||board[i][c]==ch||board[boxR][boxC]==ch) return false;
    //     }

    //     return true;
    // }
    // bool backtrack(vector<vector<char>>& board) {
    //     for (int i=0; i<board.size(); i++) {
    //         for (int j=0; j<board[0].size(); j++) {
    //             if (board[i][j]=='.') {
    //                 for (int ch='1';ch<='9';ch++) {
    //                     if (isValid(board,ch,i,j)) {
    //                         board[i][j]=ch;
    //                         if (backtrack(board)) return true;
    //                         board[i][j]='.';
    //                     }
    //                 }
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }
    
    // method 2, even slower, optimize?
    // bool backtrack(vector<vector<char>>& board, 
    // vector<unordered_set<char>>& r, 
    // vector<unordered_set<char>>& c, 
    // vector<unordered_set<char>>& b,
    // vector<pair<int,int>>& empty,
    // int idx) {
    //     if (idx==empty.size()) return true;

    //     int i = empty[idx].first;
    //     int j = empty[idx].second;
    //     int k = (i/3)*3+(j/3);

    //     for (char ch='1'; ch<='9'; ch++) {
    //         if (r[i].count(ch)==0 && c[j].count(ch)==0 && b[k].count(ch)==0) {
    //             board[i][j]=ch;
    //             r[i].insert(ch);
    //             c[j].insert(ch);
    //             b[k].insert(ch);

    //             if (backtrack(board,r,c,b,empty,idx+1)) return true;

    //             board[i][j]='.';
    //             r[i].erase(ch);
    //             c[j].erase(ch);
    //             b[k].erase(ch);
    //         }
    //     }

    //     return false;
    // }

    // method 3
    bool backtrack(vector<vector<char>>& board, int idx) {
        if (idx==emptyCells.size()) return true;

        auto [r,c] = emptyCells[idx];
        int b = (r/3)*3+(c/3);

        for (int i=0; i<9; i++) {
            if (!row[r][i]&&!col[c][i]&&!box[b][i]) {
                board[r][c]='1'+i;
                row[r][i]=col[c][i]=box[b][i]=true;

                if (backtrack(board,idx+1)) return true;

                board[r][c]='.';
                row[r][i]=col[c][i]=box[b][i]=false;
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        // method 1
        // backtrack(board);

        // method 2
        // vector<unordered_set<char>> r(9),c(9),b(9);
        // vector<pair<int,int>> empty;

        // for (int i=0; i<9; i++) {
        //     for (int j=0; j<9; j++) {
        //         if (board[i][j]!='.') {
        //             char ch=board[i][j];
        //             r[i].insert(ch);
        //             c[j].insert(ch);
        //             b[(i/3)*3+(j/3)].insert(ch);
        //         } else {
        //             empty.push_back({i,j});
        //         }
        //     }
        // }

        // backtrack(board,r,c,b,empty,0);

        // method 3
        //initialize
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (board[i][j] == '.') {
                    emptyCells.push_back({i,j});
                } else {
                    int d = board[i][j] - '1';
                    row[i][d] = col[j][d] = box[(i/3)*3 + j/3][d] = true;
                }
            }
        }
        backtrack(board, 0);
    }
};