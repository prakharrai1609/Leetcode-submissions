class Solution {
public:
    bool valid(int i, int j, int x, int y) {
        return (i >= 0 and i < x and j >= 0 and j < y);
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        pair<int, int> flag = {-1, -1};
        int time = -1, m = grid.size(), n = grid[0].size();
        int one = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                if (grid[i][j] == 1) one++;
            }
        }
        
        if (q.empty() and one) return -1; // we have oranges but none rotten
        if (!one) return 0;
        
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        
        q.push(flag);
        
        while (!q.empty()) {
            pair<int, int> temp = q.front();
            q.pop();
            
            if (temp == flag) {
                time++;
                
                if (!q.empty()) 
                    q.push(flag);
            } else {
                int x = temp.first, y = temp.second;
                
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (!valid(nx, ny, m, n)) continue;
                    
                    if (grid[nx][ny] == 1) {
                        q.push({nx, ny});
                        grid[nx][ny] = 2;
                    }
                }
            }
        }
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) 
                    return -1;
        
        return time;
    }
};