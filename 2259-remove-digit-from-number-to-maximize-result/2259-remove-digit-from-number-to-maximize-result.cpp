class Solution {
public:
    string removeDigit(string number, char digit) {
        int N = number.length();
        for (int i = 0; i < N - 1; i++) {
            if (number[i] == digit and number[i] < number[i + 1]) {
                return (number.substr(0, i) + number.substr(i + 1));
            }
        }
        
        for (int i = N - 1; i >= 0; --i) {
            if (number[i] == digit)
                return number.erase(i, 1);
        }
        
        return number;
    }
};

/*
    BAD APPROACH -- WASTAGE OF SPACE
    ================================
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
*/