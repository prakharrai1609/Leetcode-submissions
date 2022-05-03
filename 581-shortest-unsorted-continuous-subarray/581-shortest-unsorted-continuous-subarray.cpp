class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> a = nums;
        sort(a.begin(), a.end());
        int i, j, N = nums.size();
        
        for (i = 0; i < N; i++)
            if (a[i] != nums[i])
                break;
        for (j = N - 1; j >= 0; j--)
            if (a[j] != nums[j])
                break;
        if (i == N)
            return 0;
        return j - i + 1;
    }
};