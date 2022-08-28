// class Solution {
// public:
//     int maximalSquare(vector<vector<char>>& matrix) {
//         int N = matrix.size(), M = matrix[0].size();
//         int dp[N][M];
//         int ans = 0;
//         for (int i = 0; i < N; i++) {
//             for (int j = 0; j < M; j++) {
//                 if (!i or !j or matrix[i][j] == '0') {
//                     dp[i][j] = matrix[i][j] - '0';
//                 } else {
//                     dp[i][j] = min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1;
//                 }
//                 ans = max(ans, dp[i][j]);
//             }
//         }
        
//         return ans * ans;
//     }
// };

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int N = matrix.size(), M = matrix[0].size();
        vector<int> prev(M) , curr(M);
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (i == 0 or j == 0 or matrix[i][j] == '0') {
                    curr[j] = matrix[i][j] - '0';
                } else {
                    curr[j] = min({curr[j - 1], prev[j], prev[j - 1]}) + 1;
                }
                ans = max(ans, curr[j]);
            }
            swap(curr, prev);
        }
        
        return ans * ans;
    }
};