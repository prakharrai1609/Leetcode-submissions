class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int N = nums.size();
        int ans = INT_MIN, curr = 1, zero = 0, neg = 1;
        
        if (N == 1) return nums[0];
        
        for (int i = 0; i < N; i++) {
            if (nums[i] != 0) {
                curr *= nums[i];
                ans = max(ans, curr);
            } else {
                zero = 1;
                curr = 1;
            }
        }
        
        curr = 1;
        for (int i = N - 1; i >= 0; i--) {
            if (nums[i] != 0) {
                curr *= nums[i];
                ans = max(ans, curr);
            } else {
                zero = 1;
                curr = 1;
            }
        }
        
        // cout << ans << endl;
        
        if (zero)
            ans = max(ans, 0);
        // ans = max(ans, curr);
        return ans;
    }
};