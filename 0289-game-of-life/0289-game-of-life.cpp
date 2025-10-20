class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<int> dirs = {-1, 0, 1};

        auto countLive = [&](int r, int c) {
            int live = 0;
            for (int dr : dirs)
                for (int dc : dirs) {
                    if (dr == 0 && dc == 0) continue;
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                        abs(board[nr][nc]) == 1)
                        live++;
                }
            return live;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int live = countLive(i, j);
                if (board[i][j] == 1 && (live < 2 || live > 3))
                    board[i][j] = -1; // live → dead
                if (board[i][j] == 0 && live == 3)
                    board[i][j] = 2; // dead → live
            }
        }
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                board[i][j] = board[i][j] > 0 ? 1 : 0;
    }
};
