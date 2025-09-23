class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<int> res;
        vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}}; // right, down, left, up
        int dir = 0;
        int row = 0, col = 0;
        
        for (int i = 0; i < m*n; i++) {
            res.push_back(matrix[row][col]);
            visited[row][col] = true;
            
            int nextRow = row + dirs[dir][0];
            int nextCol = col + dirs[dir][1];
            
            if (nextRow < 0 || nextRow >= m || nextCol < 0 || nextCol >= n || visited[nextRow][nextCol]) {
                dir = (dir + 1) % 4;
                nextRow = row + dirs[dir][0];
                nextCol = col + dirs[dir][1];
            }
            
            row = nextRow;
            col = nextCol;
        }
        
        return res;
    }
};
