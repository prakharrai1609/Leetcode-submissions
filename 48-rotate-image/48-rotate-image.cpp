class Solution {
public:
    // BRUTE FORCE
    
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
    
    // SMART METHOD
    
    /*
     * clockwise rotate
     * first reverse up to down, then swap the symmetry 
     * 1 2 3     7 8 9     7 4 1
     * 4 5 6  => 4 5 6  => 8 5 2
     * 7 8 9     1 2 3     9 6 3
    */
    void rotate1(vector<vector<int> > &matrix) {
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i + 1; j < matrix[i].size(); ++j)
                swap(matrix[i][j], matrix[j][i]);
        }
    }

    /*
     * anticlockwise rotate
     * first reverse left to right, then swap the symmetry
     * 1 2 3     3 2 1     3 6 9
     * 4 5 6  => 6 5 4  => 2 5 8
     * 7 8 9     9 8 7     1 4 7
    */
    void anti_rotate(vector<vector<int> > &matrix) {
        for (auto vi : matrix) reverse(vi.begin(), vi.end());
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i + 1; j < matrix[i].size(); ++j)
                swap(matrix[i][j], matrix[j][i]);
        }
    }
};