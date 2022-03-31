class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int put = n + m - 1, p1 = m - 1, p2 = n - 1;
        while (p1 >= 0 and p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[put--] = nums1[p1--];
            } else {
                nums1[put--] = nums2[p2--];
            }
        }
        
        while (p2 >= 0)
            nums1[put--] = nums2[p2--];
    }
}; 