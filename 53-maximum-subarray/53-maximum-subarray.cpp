class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mxsum = -10001, maxsum = INT_MIN;
        for (int num : nums) {
            mxsum = max(mxsum + num, num);
            maxsum = max(maxsum, mxsum);
        }
        return maxsum;
    }
};