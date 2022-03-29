class Solution {
public:
    void sortColors(vector<int>& nums) {
        int N = nums.size();
        int l = 0, m = 0, r = N - 1;
        while (m <= r) {
            switch (nums[m]) {
                case 0:
                    swap(nums[l++], nums[m++]);
                    break;
                case 1:
                    m++;
                    break;
                case 2:
                    swap(nums[m], nums[r--]);
                    break;
            }   
        }
    }
};