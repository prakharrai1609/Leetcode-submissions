class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pTriangle;
        pTriangle.push_back({1});
        
        for (int i = 1; i < numRows; i++) {
            vector<int> temp(i + 1);
            temp[0] = temp[i] = 1;
            for (int j = 1; j < i; j++) {
                temp[j] = pTriangle[i - 1][j - 1] + pTriangle[i - 1][j];
            }
            pTriangle.push_back(temp);
        }
        
        return pTriangle;
    }
};
