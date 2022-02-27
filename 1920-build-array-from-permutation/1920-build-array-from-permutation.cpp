// TIME : O(N) SPACE : O(N)
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
};

// Optimization over the O(N) space solution!
// TIME : O(N) SPACE : O(1)
/*
 How?
 - let's say a number x is changed to x = x + n * (y % n)
 - now adding x to z => z = z + n * ((x + n * (y % n)) % n) => z + n * x
 - later divide by n to remove the extra remainder
*/
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[i] += n * (nums[nums[i]] % n);
        }
        
        for (int i = 0; i < n; i++) 
            nums[i] /= n;
        
        return nums;
    }
};
