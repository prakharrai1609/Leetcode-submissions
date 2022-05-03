class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        /*
            Approach: 
            - storing all the indices in the vector
            - calculating the pair wise minimum
        */
        map<int, vector<int>> m;
        for (int i = 0; i < cards.size(); i++) {
            m[cards[i]].push_back(i + 1);
        }
        
        int ans = INT_MAX;
        for (auto x : m) {
            if (x.second.size() > 1) {
                vector<int> a = x.second;
                for (int i = 1; i < a.size(); i++) {
                    ans = min(ans, a[i] - a[i - 1] + 1);
                }
            }
        }
        
        return (ans == INT_MAX ? -1 : ans);
    }
};