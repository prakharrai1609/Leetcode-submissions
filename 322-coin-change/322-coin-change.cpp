class Solution {
    const int N = 1e5;
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, N);
        dp[0] = 0;
        
        for (int amt = 1; amt <= amount; ++amt) {
            for (int i = 1; i <= coins.size(); i++) {
                if (coins[i - 1] <= amt) {
                    dp[amt] = min(dp[amt], 1 + dp[amt - coins[i - 1]]);
                }
            }
        }
        
        return (dp[amount] == N ? -1 : dp[amount]);
    }
};