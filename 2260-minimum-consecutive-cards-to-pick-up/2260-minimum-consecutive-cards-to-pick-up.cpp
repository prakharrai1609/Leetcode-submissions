class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int prev[1000001] = {0}, ans = INT_MAX;
        
        for (int i = 0; i < cards.size(); i++) {
            if (prev[cards[i]])
                ans = min(ans, (i + 1) - prev[cards[i]] + 1);
            prev[cards[i]] = i + 1;
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};
    
/*
    Approach: 
    - storing all the indices in the vector
    - calculating the pair wise minimum

    Improvement:
    - instead of keeping track of all the indices
    just keep track of previous value

    CODE
    ====
        unordered_map<int, vector<int>> m;
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
*/