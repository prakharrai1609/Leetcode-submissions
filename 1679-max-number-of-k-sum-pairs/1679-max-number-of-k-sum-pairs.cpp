class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int, int> m;
        for (int n : nums) m[n]++;
        int ans = 0;
        for (auto x : m) {
            int n = x.first;
            if (n != k - n)
                ans += min(m[n], m[k - n]);
            else
                ans += m[n] / 2;
            m[n] = m[k - n] = 0;
        }
        return ans;
    }
};