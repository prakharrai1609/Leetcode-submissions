class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int N = nums.size(), counter = 0, prev = INT_MIN;
        
        for (int i = 0; i < N - 1; i++) {
            if (nums[i] <= nums[i + 1]) {
                prev = nums[i];
            } else {
                if (nums[i + 1] < prev) 
                    nums[i + 1] = nums[i];
                counter++;
            }
        }
        
        return (counter <= 1) ? 1 : 0;
    }
};