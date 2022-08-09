class Solution {
public: 
    bool validPartition(vector<int>& nums) {
        int N = size(nums);
        vector<int> dp(N + 1, 0);
        
        dp[0] = 1;
        for (int i = 1; i < N; i++) {
            if (nums[i] == nums[i - 1]) 
                dp[i + 1] = (dp[i + 1] || dp[i - 1]);
            if (i >= 2) {
                if (nums[i] == nums[i - 1] and nums[i - 1] == nums[i - 2]) 
                    dp[i + 1] = (dp[i + 1] || dp[i - 2]);
                if (nums[i] == nums[i - 1] + 1 and nums[i - 1] == nums[i - 2] + 1) 
                    dp[i + 1] = (dp[i + 1] || dp[i - 2]);
            }
        }
        
        return dp[N] == 1;
    }
};


/* RECURSION + MEMOISATION

class Solution {
    vector<int> dp;
public:
    bool partition(vector<int>& nums, int idx) {
        int N = nums.size();
        
        if (idx >= N)
            return 1;
        
        if (dp[idx] != -1)
            return dp[idx];
        
        int ans = 0;
        
        if ((idx + 1 < N) && (nums[idx] == nums[idx + 1]))
            ans |= partition(nums, idx + 2);
        
        if ((idx + 2 < N) && (nums[idx] == nums[idx + 1]) && (nums[idx] == nums[idx + 2]))
            ans |= partition(nums, idx + 3);
        
        if ((idx + 2 < N) && (nums[idx] == nums[idx + 1] - 1) && (nums[idx] == nums[idx + 2] - 2))
            ans |= partition(nums, idx + 3);
        
        return dp[idx] = ans;
    }
    
    
    bool validPartition(vector<int>& nums) {
        dp.resize(nums.size() + 1, -1);
        return partition(nums, 0);
    }
};

*/