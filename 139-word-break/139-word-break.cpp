/* 
    solution 1
    ==========

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

    solution 2
    ==========

class Solution {
    unordered_map<string, bool> m;
    vector<int> dp;
    
public:
    bool f(string s, int idx) {
        if (idx == s.length())
            return 1;
        
        if (dp[idx] != -1)
            return dp[idx];
        
        for (int i = idx + 1; i <= s.length(); i++) {
            if (m[s.substr(idx, i - idx)]) {
                bool rec = f(s, i);
                if (rec)
                    return dp[idx] = 1;
            }
        }
        
        return dp[idx] = 0;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.resize(301, -1);
        for (string word : wordDict) m[word] = 1;
        return f(s, 0);   
     }
};
*/

class Solution {
    unordered_map<string, bool> m;
public:        
    bool wordBreak(string s, vector<string>& wordDict) {
        int N = s.length();
        vector<bool> dp(N + 1, false);
        for (string word : wordDict) m[word] = 1;
        dp[0] = true;
        
        for (int i = 1; i <= N; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] and m[s.substr(j, i - j)]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[N];
    }
};