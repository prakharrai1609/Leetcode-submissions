class Solution {
public:
    double binPow(double N, int P) {
        double res = 1.0;
    
        while (P) {
            if (P & 1) {
                if (P > 0)
                    res *= N;
                else 
                    res /= N;
            } 
            N *= N;
            P /= 2;
        }
        
        return res;
    }
    
    double myPow(double x, int n) {        
        // learn about bin-exp at : https://cp-algorithms.com/algebra/binary-exp.html
        return binPow(x, n);
    }
};