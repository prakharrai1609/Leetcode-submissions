class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // think about this like paper folding, how will you fold the paper to get the desired shape
        // first fold the matrix about first row 
        
        int fr = 0, lr = matrix.size() - 1, N = matrix[0].size();
        
        while (fr < lr) {
            for (int j = 0; j < N; j++) {
                swap(matrix[fr][j], matrix[lr][j]);
            }
            fr++, lr--;
        }
        
        // now matrix is flipped across the first row
        // now we flip it along diagonal to get the desired reflection
        
        // top triangle        
        int row1, col1, row2, col2;
        for (int i = 0; i < N; i++) {
            row1 = 0, col1 = i, row2 = i, col2 = 0;
            while (row1 < row2) {
                swap(matrix[row1][col1], matrix[row2][col2]);
                row1++, row2--;
                col1--, col2++;
            }
        }
        
        // bottom triangle
        for (int i = 1; i < N; i++) {
            row1 = i, col1 = N - 1, row2 = N - 1, col2 = i;
            while (row1 < row2) {
                swap(matrix[row1][col1], matrix[row2][col2]);
                row1++, row2--;
                col1--, col2++;
            }
        }
    }
};