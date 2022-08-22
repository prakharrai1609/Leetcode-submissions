// class Solution {
//     // vector<int> dp;
//     map<pair<int, int>, int> m;
// public:
//     int earn(vector<pair<int, int>>& a, int idx, int prev) {
//         if (idx == a.size())
//             return 0;
        
//         if (m[{idx, prev}])
//             return m[{idx, prev}];
        
//         int op1 = 0, op2 = 0, num = a[idx].first, freq = a[idx].second;
        
//         if (num != prev + 1) 
//             op1 = (num * freq) + earn(a, idx + 1, num);
//         op2 = earn(a, idx + 1, prev);
        
//         return m[{idx, prev}] = max(op1, op2);
//     }
    
//     int deleteAndEarn(vector<int>& nums) {
//         unordered_map<int, int> m;
        
//         for (int num : nums) m[num]++;
        
//         vector<pair<int, int>> a;
//         for (auto [num, freq] : m) {
//             a.push_back({num, freq});
//         }
//         sort(a.begin(), a.end());
//         return earn(a, 0, -1);
//     }
// };

class Solution {
    const int N = 10001;
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> f(N, 0);
        vector<int> dp(N, 0);
        
        for (int num : nums) f[num]++;
        
        dp[1] = f[1];
        
        for (int i = 2; i < N; i++) {
            dp[i] = max(dp[i - 2] + i * f[i], dp[i - 1]);
        }
        
        return dp[N - 1];
    }
};