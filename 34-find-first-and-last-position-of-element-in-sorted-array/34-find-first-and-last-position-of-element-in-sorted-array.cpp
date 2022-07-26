class Solution {
public:
    int ub(const vector<int>& a, int target) {
        int l = 0, r = size(a) - 1, ans = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (a[m] > target) {
                r = m - 1;
            } else {
                if (a[m] == target) ans = m;
                l = m + 1;
            }
        }
        return ans;
    }
    
    int lb(const vector<int>& a, int target) {
        int l = 0, r = size(a) - 1, ans = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (a[m] >= target) {
                if (a[m] == target) ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lb(nums, target);
        int r = ub(nums, target);
        return {l, r};
    }
};