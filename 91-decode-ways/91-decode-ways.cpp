class Solution {
    vector<int> dp;
public:
    int count(string s, int i) {
        if (i == s.length())
            return 1;
        
        if (s[i] == '0')
            return 0;
        
        if (dp[i] != -1)
            return dp[i];
        
        int op1 = 0, op2 = 0;
        
        // pick 1 char
        op1 = count(s, i + 1);
        // pick 2 char
        if (i + 1 < s.length()) {
            if (s[i] == '1') {
                op2 = count(s, i + 2);
            } else if (s[i] == '2' and s[i + 1] < '7') {
                op2 = count(s, i + 2);
            }
        }
        
        return dp[i] = op1 + op2;
    }
    
    int numDecodings(string s) {
        dp.resize(s.length(), -1);
        return count(s, 0);   
    }
};