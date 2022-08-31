class Solution {
    int R, C;
    bool pacific, atlantic;
    map<pair<int, int>, bool> found;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
public:
    bool out(int r, int c) {
        return (r < 0 or c < 0 or r >= R or c >= C);
    }
    
    bool inpacific(int r, int c) {
        return ((r < 0) or (c < 0 and r < R));
    }
    
    bool inatlantic(int r, int c) {
        return ((r >= R) or (c >= C and r >= 0));
    }
    
    void bfs(int r, int c, vector<vector<int>>& grid) {
        map<pair<int, int>, bool> vis;
        queue<pair<int, int>> q;
        q.push({r, c});
        
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            
            int row = p.first, col = p.second;
            
            if (found.count(p) and found[p]) {
                pacific = atlantic = true;
                return;
            }
            
            if (inpacific(row, col)) {
                pacific = true;
                continue;
            }
            
            if (inatlantic(row, col)) {
                atlantic = true;
                continue;
            }
            
            if (pacific and atlantic)
                return;
            
            if (vis[p])
                continue;
            
            vis[p] = true;
            
            for (int i = 0; i < 4; i++) {
                int tr = row + dx[i];
                int tc = col + dy[i];
                
                if ((out(tr, tc) or (grid[tr][tc] <= grid[row][col])) and !vis[{tr, tc}]) {
                    q.push({tr, tc});
                }
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        R = heights.size(), C = heights[0].size();
        vector<vector<int>> ans;
        
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                pacific = atlantic = false;
                bfs(i, j, heights);
                
                if (pacific and atlantic) {
                    found[{i, j}] = true;
                    ans.push_back({i, j});
                }
            }
        }
        
        return ans;
    }
};