class Solution {
private:
    vector<vector<int>> ans;
public:
    /*
        BACKTRACKING BASED SOLUTION:
        ===========================        
    */
    
    
    int sum(const vector<int>& combo) {
        int temp = 0;
        for (int x : combo)
            temp += x;
        return temp;
    }
    
    void helper(vector<int>& combo, int k, int n, int num) {
        if (!k) {
            if (sum(combo) == n)
                ans.push_back(combo);
            return;
        }
        
        if (num > 9) return;
        
        combo.push_back(num);
        helper(combo, k - 1, n, num + 1);
        combo.pop_back();
        helper(combo, k, n, num + 1);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> combo;
        helper(combo, k, n, 1);
        return ans;
    }
};

    
/*
    BRUTE FORCE | BIT MANIPULATION
    ==============================


	This solution involves checking all possible combinations possible :
	- "int bits = __builtin_popcount(i);" here we check if their are K numbers or not
	- if there are K numbers present, then we just check the sum of all 


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        for (int i = 0; i < (1 << 9); i++) {
            vector<int> combo;
            int bits = __builtin_popcount(i);
            if (bits != k) continue;
            
            int temp = 0;
            for (int j = 0; j < 9; j++) {
                if (i & (1 << j)) {
                    temp += (j + 1);
                    combo.push_back(j + 1);
                }
            }
            
            if (temp == n)
                ans.push_back(combo);
        }
        
        return ans;
    }
};

*/