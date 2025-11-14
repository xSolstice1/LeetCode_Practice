class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n+1, vector<int>(n+1, 0));

        for (auto& q : queries) {
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
            diff[r1][c1] += 1;
            diff[r1][c2+1] -= 1;
            diff[r2+1][c1] -= 1;
            diff[r2+1][c2+1] += 1;
        }

        vector<vector<int>> mat(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int a = diff[i][j];
                if (i) a += mat[i-1][j];
                if (j) a += mat[i][j-1];
                if (i && j) a -= mat[i-1][j-1];
                mat[i][j] = a;
            }
        }
        return mat;
    }
};