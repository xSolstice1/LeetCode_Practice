class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size()-1, m=grid[0].size()-1;
        for (int i=0; i<=n; i++) {
            for (int j=0; j<=m; j++) {
                if (i==0 && j==0) continue;
                else if (i==0) grid[i][j] += grid[i][j-1];
                else if (j==0) grid[i][j] += grid[i-1][j];
                else grid[i][j] += min(grid[i][j-1],grid[i-1][j]);
            }
        }

        return grid[n][m];
    }
};