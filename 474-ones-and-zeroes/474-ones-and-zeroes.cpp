class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        
        for (string s : strs) {
            int zero = count(s.begin(), s.end(), '0');
            int one = count(s.begin(), s.end(), '1');
            
            for (int i = m; i >= zero; i--) {
                for (int j = n; j >= one; j--) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zero][j - one]);
                }
            }
        }
        
        return dp[m][n];
    }
};


/*

    RECURSIVE APPROACH
    ==================
    
    int subs(const vector<string>& vc, int m, int n, int N) {
        if ((!m and !n) or !N)
            return 0;
        
        if (dp[N][m][n] != -1)
            return dp[N][m][n];
        
        int z = 0, o = 0;
        
        for (char c : vc[N - 1]) {
            if (c == '0') z++;
            else o++;
        }
        
        int op1 = 0;
        
        if (m >= z and n >= o)
            op1 = 1 + subs(vc, m - z, n - o, N - 1);
        int op2 = subs(vc, m, n, N - 1);
        
        return dp[N][m][n] = max(op1, op2);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        dp.resize(N + 1, vector<vector<int>> (m + 1, vector<int> (n + 1, -1)));
        
        return subs(strs, m, n, N);
    }


*/