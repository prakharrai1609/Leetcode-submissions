class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int N = matrix.size(), M = matrix[0].size();
        int dp[N][M];
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!i or !j or matrix[i][j] == '0') {
                    dp[i][j] = matrix[i][j] - '0';
                } else {
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        
        return ans * ans;
    }
};