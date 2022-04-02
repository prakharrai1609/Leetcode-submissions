class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // first find the best row to search in 
        // then find the colm
        
        // looking for the row
        int top = 0, bottom = matrix.size() - 1, ans = -1;
        while (top <= bottom) {
            int mid = (top + bottom) / 2;
            if (matrix[mid][0] > target)
                bottom = mid - 1;
            else
                ans = mid, top = mid + 1; 
        }
        
        if (ans == -1) {
            return false;
        }
        
        // searching in column
        int l = 0, r = matrix[0].size() - 1, row = ans;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (matrix[row][mid] == target)
                return true;
            else if (matrix[row][mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        
        return false;
    }
};