class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> rows;

        for (int i=0; i<n; i++) {
            rows[grid[i]]++;
        }

        int res = 0;

        for (int i=0; i<n; i++) {
            vector<int> cols;
            for (int j=0; j<n; j++) {
                cols.push_back(grid[j][i]);
            }
            if (rows.count(cols)) {
                res+=rows[cols];
            }
        }

        return res;
    }
};