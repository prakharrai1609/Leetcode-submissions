class Solution {
    vector<vector<int>> dp;
    unordered_map<string, bool> m;
public:
    bool f(string s, int i, int j) {
        if (j == s.length())
            return m[s.substr(i, j - i + 1)];
        
        if (dp[i][j] != -1) 
            return dp[i][j];
        
        bool op1 = false, op2 = false;
        
        if (m[s.substr(i, j - i + 1)])
            op1 = f(s, j + 1, j + 1);
        op2 = f(s, i, j + 1);
        
        return dp[i][j] = (op1 || op2);
    }
        
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.resize(s.length(), vector<int> (s.length(), -1));
        for (string word : wordDict) m[word] = 1;
        return f(s, 0, 0);   
     }
};