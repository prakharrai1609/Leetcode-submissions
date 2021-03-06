class Solution {
    map<int, int> vis;
    int sum = 0, ans = 0;
public:
/*
    A little tricky DFS
    -------------------

    void dfs1(map<int, vector<int>>& m, int src, const vector<int>& it) {
        vis[src] = 1;
        sum += it[src];
        
        for (int nbr : m[src]) {
            if (!vis[nbr]) {
                dfs1(m, nbr, it);
            }
        }
        
        ans = max(sum, ans);
        sum -= it[src];
    }
  
*/

// SIMPLER DFS
    
    int dfs2(map<int, vector<int>>& m, int src, vector<int>& informTime) {
        int mx = 0;
        for (int nbr : m[src]) 
            mx = max(mx, dfs2(m, nbr, informTime));
        return mx + informTime[src];
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        if (n == 1) return 0;
        
        map<int, vector<int>> m; // manager, list<employees>
        for (int i = 0; i < n; i++) {
            if (i == headID) continue;
            m[manager[i]].push_back(i);
        }
        
        // dfs1(m, headID, informTime);
        return dfs2(m, headID, informTime);
    }
};