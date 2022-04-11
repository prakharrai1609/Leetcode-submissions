class Solution {
public:
    void turn(vector<vector<int>> &grid) {
        int r = grid.size(), c = grid[0].size();
        for (int i = 0; i < r; i++)
            rotate(grid[i].begin(), grid[i].begin() + grid[i].size() - 1, grid[i].end());
        int temp = grid[r - 1][0];
        for (int i = r - 1; i >= 1; i--) {
            grid[i][0] = grid[i - 1][0];
        }
        grid[0][0] = temp;
    }
    
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        while (k--)
            turn(grid);
        return grid;
    }
};