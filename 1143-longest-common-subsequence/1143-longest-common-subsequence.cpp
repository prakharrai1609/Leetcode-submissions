class Solution {
private:
    vector<vector<int>> dp;
public:
//     int lcs(string t1, string t2, int i, int j) {
//         if (i >= t1.length() or j >= t2.length())
//             return 0;
        
//         if (dp[i][j] != -1)
//             return dp[i][j];
        
//         if (t1[i] == t2[j]) return dp[i][j] = 1 + lcs(t1, t2, i + 1, j + 1);
//         else return dp[i][j] = max(lcs(t1, t2, i + 1, j), lcs(t1, t2, i, j + 1));
//     }
    
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.length(), l2 = text2.length();
        // dp.resize(l1, vector<int> (l2, -1));
        // return lcs(text1, text2, 0, 0);
        
        dp.resize(l1 + 1, vector<int> (l2 + 1, 0));
        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        return dp[l1][l2];
    }
};