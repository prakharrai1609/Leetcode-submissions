class Solution {
private:
    vector<vector<vector<int>>> dp;
public:
    /*
        m - zero's limit
        n - one's limit
    */
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
};