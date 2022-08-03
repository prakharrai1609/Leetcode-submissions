class Solution {
public:
    bool boundcheck(int i, int j, int m, int n) {
        if (i >= m or i < 0) return false;
        if (j >= n or j < 0) return false;
        return true;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = size(matrix), n = size(matrix[0]), i = 0, j = n - 1;
        
        while (boundcheck(i, j, m, n)) {
            
            if (matrix[i][j] == target) 
                return true;
            
            if (matrix[i][j] > target) {
                j--;
                continue;
            }
            
            // matrix[i + 1][j]
            i++;
        }
        
        return false;
    }
};