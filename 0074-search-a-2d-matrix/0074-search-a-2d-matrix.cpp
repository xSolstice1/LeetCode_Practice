class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size(); //col and row
        int left = 0, right = m*n-1; //left and right

        while (left <= right) {
            int mid = left + (right-left) / 2;

            int r = mid/m; //row index
            int c = mid%m; //col index

            if (matrix[r][c] == target) {
                return true; //target found
            } else if (matrix[r][c] < target) {
                left = mid+1; //shift left pointer
            } else {
                right = mid-1; //shift right pointer
            }
        }

        return false;
    }
};