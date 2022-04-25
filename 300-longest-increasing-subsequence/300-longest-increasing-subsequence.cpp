class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for (int num : nums)
        {
            auto lb = lower_bound(lis.begin(), lis.end(), num);                     
            if (lb == lis.end()) lis.push_back(num);
            else *lb = num;
        }
        return lis.size();
    }
};