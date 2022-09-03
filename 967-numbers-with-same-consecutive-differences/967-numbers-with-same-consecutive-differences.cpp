class Solution {
    int start, end;
    vector<int> ans;
public:
    void make(int num, int n, int k) {
        if (n == 1) {
            ans.push_back(num);
            return;
        }
        
        int last = num % 10;
        if (last + k < 10)
            make(num * 10 + last + k, n - 1, k);
        if (last - k >= 0 and k) 
            make(num * 10 + last - k, n - 1, k);
    }
        
    vector<int> numsSameConsecDiff(int n, int k) {
        start = 1;
        end = n;
        for (int i = 1; i < 10; i++) {
            make(i, n, k);
        }
        return ans;
    }
};