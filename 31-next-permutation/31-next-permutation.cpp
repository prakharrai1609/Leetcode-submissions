class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int N = nums.size(), left = -1, right;
        
        // find out first the right-most posn where order can be changed
        // rightmost because we are looking for the just greater number
        for (int i = N - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                left = i;
                break;
            }
        }
        
        if (left == -1) {
            return void(reverse(nums.begin(), nums.end()));
        }
        
        for (int i = N - 1; i >= left; i--) {
            if (nums[i] > nums[left]) {
                right = i;
                break;
            }
        }
        
        swap(nums[left], nums[right]);
        reverse(nums.begin() + left + 1, nums.end());
    }
};