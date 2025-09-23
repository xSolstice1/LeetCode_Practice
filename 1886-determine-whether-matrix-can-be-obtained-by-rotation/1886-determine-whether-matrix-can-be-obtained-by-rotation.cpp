class Solution {
private:
    void rotate(vector<vector<int>>& matrix) {
        //transpose+reverse?

        for (int i=0; i<matrix.size(); i++) {
            for (int j=i+1; j<matrix[0].size(); j++) {
                swap(matrix[i][j],matrix[j][i]); // row <-> column swap
            }
        }

        for (int i=0; i<matrix.size(); i++) {
            reverse(matrix[i].begin(),matrix[i].end()); // reverse each row
        }
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int i=0; i<4; i++) {
            if (mat == target) return true;
            rotate(mat);
        }

        return mat == target;
    }
};