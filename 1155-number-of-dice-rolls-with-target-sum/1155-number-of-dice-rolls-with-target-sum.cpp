class Solution {
    vector<vector<int>> dp;
    int MOD = int(1e9 + 7);
public:
    int solve(int n, int k, int target) {
        if (n == 0 and target == 0)
            return 1;
        
        if (!n)
            return 0;
        
        if (dp[n][target] != -1)
            return dp[n][target];
        
        int result = 0;
        for (int i = 1; i <= k; i++) {
            if (target >= i)
                result = (result + solve(n - 1, k, target - i)) % MOD;
        }
        
        return dp[n][target] = result;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        if (target > n * k)
            return 0;
        
        dp.resize(n + 1, vector<int> (target + 1, -1));
        return solve(n, k, target);
    }
};