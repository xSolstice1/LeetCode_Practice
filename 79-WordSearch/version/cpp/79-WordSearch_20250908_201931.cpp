// Last updated: 9/8/2025, 8:19:31 PM
/*
 * DFS/Backtracking
 * 
 * Base Case - index = word.size()
 * Pruning - row/col < 0 or row/col >= board/board[0].size or char <> target char
 * DFS 4 directions row+1,row-1,col+1,col-1, update index and backtrack
*/

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int row, int col, int index) {
        if (index == word.size()) return true;

        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index]) {
            return false;
        }

        char temp = board[row][col];
        board[row][col] = '.';

        bool found =
        dfs(board,word,row,col+1,index+1) ||
        dfs(board,word,row,col-1,index+1) ||
        dfs(board,word,row+1,col,index+1) ||
        dfs(board,word,row-1,col,index+1);

        board[row][col] = temp;

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (dfs(board,word,i,j,0)) return true;
            }
        }

        return false;
    }
};