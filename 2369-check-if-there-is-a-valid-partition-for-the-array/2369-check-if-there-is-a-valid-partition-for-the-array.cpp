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