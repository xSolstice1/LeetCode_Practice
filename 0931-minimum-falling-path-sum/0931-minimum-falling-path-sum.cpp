class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp = matrix[n-1]; //start from bottom row

        //build from bottom-1 row up
        for (int i = n-2; i >= 0; i--) {
            vector<int> newDp(n, 0);
            for (int j = 0; j < n; j++) {
                int down = dp[j];
                int left = (j > 0) ? dp[j-1] : INT_MAX;
                int right = (j < n-1) ? dp[j+1] : INT_MAX;
                newDp[j] = matrix[i][j] + min({down, left, right});
            }
            dp = newDp;
        }

        return *min_element(dp.begin(), dp.end());
    }
};