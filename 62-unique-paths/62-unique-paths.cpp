class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        
        for (int i = 0; i <= m; ++i) dp[i][n] = 1;
        for (int j = 0; j <= n; ++j) dp[m][j] = 1;
        
        for (int i = m - 1; i >= 1; i--) {
            for (int j = n - 1; j >= 1; j--) {
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }
        
        return dp[1][1];
    }
};