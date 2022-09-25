class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int N = v.size();
        if (k >= N)
            return accumulate(v.begin(), v.end(), 0);
        vector<int> pre(N + 1, 0), suff(N + 2, 0);
        
        pre[1] = v[0];
        for (int i = 2; i <= N; i++) pre[i] = pre[i - 1] + v[i - 1];
        
        suff[N] = v[N - 1];
        for (int i = N - 1; i >= 1; i--) suff[i] = suff[i + 1] + v[i - 1];
        
        int ans = 0;
        for (int i = 0; i <= k; i++) {
            int left = pre[i];
            int right = suff[N - (k - i) + 1];
            ans = max(ans, left + right);
        }
        
        return ans;
    }
};