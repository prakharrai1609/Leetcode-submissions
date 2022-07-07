class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> res;
        stack<int> s;
        
        for (int i = size(nums2) - 1; i >= 0; i--) {
            while (!s.empty() and s.top() < nums2[i]) {
                s.pop();
            }
            res[nums2[i]] = (s.empty() ? -1 : s.top());
            s.push(nums2[i]);
        }
        
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(res[num]);
        }
        
        return ans;
    }
};