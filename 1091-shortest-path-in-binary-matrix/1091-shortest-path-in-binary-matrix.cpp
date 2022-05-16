class Solution {
public:
    bool check(vector<vector<int>>& grid, int i, int j) {
        int N = grid.size();
        return !(i >= N or j >= N or i < 0 or j < 0);
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int dx[8] = {1, 0, 1, -1, -1, -1, 0, 1};
        int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
        
        if (grid[0][0])
            return -1;
        
        queue<vector<int>> q;
        q.push({0, 0, 1});
        
        int N = grid.size();
        
        while (!q.empty()) {
            vector<int> v = q.front();
            q.pop();
            
            int row = v[0], col = v[1], steps = v[2];
            
            if (row == N - 1 and col == N - 1) 
                return steps;
            
            for (int i = 0; i < 8; i++) {
                int x_cor = row + dx[i], y_cor = col + dy[i];

                if (check(grid, x_cor, y_cor)) {
                   if (!grid[x_cor][y_cor]) {
                       q.push({x_cor, y_cor, steps + 1});
                       grid[x_cor][y_cor] = 1;
                   }
                }
            }  
        }
        
        return -1;
    }
};