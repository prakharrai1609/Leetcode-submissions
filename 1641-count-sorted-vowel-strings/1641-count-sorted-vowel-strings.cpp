class Solution {
    int a = 1, e = 1, i = 1, o = 1, u = 1;
public:
    void round() {
        a += e + i + o + u;
        e += i + o + u;
        i += o + u;
        o += u;
    }
    
    int countVowelStrings(int n) {
        n -= 1;
        while (n--)
            round();
        return a + e + i + o + u;
    }
};

/*
    MATH BASED APPROACH
    -------------------
    
    - we know that if we have some sets (1 to 4) of (a, e, i, o, u), a will be incremented as :
        # (a, e, i, o, u) (a, e, i, o, u) (a, e, i, o, u)
        # [[aa ae ai ao au] [ee, ei, eo, eu], .. [uu]] (a, e, i, o, u)
        # and so on, we can understand that easily
*/