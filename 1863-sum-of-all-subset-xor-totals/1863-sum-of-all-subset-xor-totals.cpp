class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int N = nums.size(), sum = 0;
        
        for (int i = 0; i < (1 << N); i++) {
            int x = 0;
            for (int j = 0; j < N; j++) {
                x ^= (i & (1 << j)) ? nums[j] : 0;
            }
            sum += x;
        }
        
        return sum;
    }
};