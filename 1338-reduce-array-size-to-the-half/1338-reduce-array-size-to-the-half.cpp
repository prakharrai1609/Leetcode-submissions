class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> cnt;
        for (int x : arr) ++cnt[x];

        vector<int> counting(n + 1);
        for (auto [_, freq] : cnt) ++counting[freq];

        int ans = 0, removed = 0, half = n / 2, freq = n;
        while (removed < half) {
            ans += 1;
            while (counting[freq] == 0) --freq;
            removed += freq;
            --counting[freq];
        }
        return ans;
    }
};

// class Solution {
// public:
//     int minSetSize(vector<int>& arr) {
//         map<int, int> f;
//         vector<pair<int, int>> v;
//         for (int i = 0; i < arr.size(); i++)
//             f[arr[i]]++;
//         for (auto x : f)
//             v.push_back({x.second, x.first});
//         sort(v.begin(), v.end(), greater<pair<int, int>>());
//         int cnt = 0, ans = 0, N = arr.size();
//         N /= 2;
        
//         for (auto p : v) {
//             if (cnt >= N) break;
//             ans++;
//             N -= p.first;
//         }
        
//         return ans;
//     }
// };