class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> f1, f2;
        for (char c : ransomNote) f1[c]++;
        for (char c : magazine) f2[c]++;
        
        for (char c : ransomNote) {
            if (f1[c] > f2[c])
                return false;
        }
        
        return true;
    }
};