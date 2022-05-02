class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int N = nums.size();
        for (int i = 0, j = 0; i < N; i++)
            if (nums[i] % 2 == 0) 
                swap(nums[i], nums[j++]);
                
        return nums;
    }
};