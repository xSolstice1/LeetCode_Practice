class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int row, int col, int index) {
        if (index == word.size()) return true; //base case, whole word is formed

        //check if row/col out of bounds or target char != word char
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index]) {
            return false;
        }

        char temp = board[row][col];
        board[row][col] = '.';

        //dfs all 4 directions
        bool found =
        dfs(board,word,row,col+1,index+1) ||
        dfs(board,word,row,col-1,index+1) ||
        dfs(board,word,row+1,col,index+1) ||
        dfs(board,word,row-1,col,index+1);

        board[row][col] = temp; //backtrack

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