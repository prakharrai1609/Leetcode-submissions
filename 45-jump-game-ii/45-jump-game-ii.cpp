class Solution {
public:
    int jump(vector<int>& nums) {
        int R = nums[0], maxR = nums[0], N = size(nums), steps = 0;
        
        for (int i = 1; i < N; i++) {
            if (R >= N - 1)
                return steps + 1;
            
            maxR = max(maxR, nums[i] + i);
            
            if (i == R) {
                // reach ended
                R = maxR;
                steps++;
            }            
        }
        
        return steps;
    }
};