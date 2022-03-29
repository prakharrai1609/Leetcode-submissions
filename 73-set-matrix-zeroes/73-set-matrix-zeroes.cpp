class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int cols = matrix[0].size(), rows = matrix.size();
        bool row_find = false, col_find = false;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0) row_find = true;
                    if (j == 0) col_find = true;
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (!matrix[i][0] or !matrix[0][j])
                    matrix[i][j] = 0;
            }
        }
        
        if (row_find) for (int j = 0; j < cols; j++) matrix[0][j] = 0;
        if (col_find) for (int i = 0; i < rows; i++) matrix[i][0] = 0;
    }
};