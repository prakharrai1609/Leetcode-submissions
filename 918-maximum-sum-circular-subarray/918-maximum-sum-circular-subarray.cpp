class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int mnsum = 0, mxsum = 0, minsum = INT_MAX, maxsum = INT_MIN, total = 0;
        
        for (int num : nums) {
            total += num;
            
            mnsum = min(mnsum + num, num);
            minsum = min(minsum, mnsum);
            mxsum = max(mxsum + num, num);
            maxsum = max(maxsum, mxsum);
        }
        
        return maxsum > 0 ? max(total - minsum, maxsum) : maxsum;
    }
};