class Solution {
    vector<int> dp;
public:
    int solve(string s, int idx) {
        if (idx >= s.length())
            return 1;
        int op1 = 0, op2 = 0;
        if (s[idx] == '0')
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        op1 = solve(s, idx + 1);
        if (idx + 1 < s.length()) {
            int num = ((s[idx + 1] - '0') + 10 * (s[idx] - '0'));
            if (num <= 26)
                op2 = solve(s, idx + 2);
        }
        
        return dp[idx] = op1 + op2;
    }
    
    int numDecodings(string s) {
        dp.resize(s.length(), -1);       
        return solve(s, 0);
    }
};