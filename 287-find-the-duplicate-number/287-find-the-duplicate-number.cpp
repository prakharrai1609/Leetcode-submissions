class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int N = nums.size();
        
        for (int i = 0; i < N; i++) {
            if (nums[abs(nums[i]) - 1] < 0) {
                return abs(nums[i]);
            }
            
            nums[abs(nums[i]) - 1] *= -1;
        }
        
        return 0;
    }
};