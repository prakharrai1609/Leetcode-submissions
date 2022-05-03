class Solution {
public:
    string removeDigit(string number, char digit) {
        vector<string> db;
        int N = number.length();
        
        for (int i = 0; i < N; i++) {
            if (number[i] == digit) {
                string s = number.substr(0, i) + ((i == N - 1) ? "" : number.substr(i + 1));
                db.push_back(s);
            }
        }
        
        string ans = *max_element(db.begin(), db.end());
        return ans;
    }
};