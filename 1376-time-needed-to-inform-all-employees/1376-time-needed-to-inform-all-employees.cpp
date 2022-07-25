class Solution {
    map<int, int> vis;
    int sum = 0, ans = 0;
public:
    void dfs(map<int, vector<int>>& m, int src, const vector<int>& it) {
        vis[src] = 1;
        sum += it[src];
        
        bool isManager = 0;
        
        for (int nbr : m[src]) {
            if (!vis[nbr]) {
                isManager = 1;
                dfs(m, nbr, it);
            }
        }
        
        sum -= it[src];
        if (!isManager) ans = max(sum, ans);
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        if (n == 1) return 0;
        
        map<int, vector<int>> m; // manager, list<employees>
        for (int i = 0; i < n; i++) {
            if (i == headID) continue;
            m[manager[i]].push_back(i);
        }
        
        dfs(m, headID, informTime);
        return ans;
    }
};