class Solution {
public:
    int countPrimes(int n) {
        if(n<2){
            return 0;
        }
        vector<bool> ar(n,true);
        ar[0]=false;
        ar[1] = false;
        for(long long i = 2; i*i<n; i++){
            if(ar[i]){
                for(long long j = i*2 ; j < n ; j += i){
                    ar[j]=false;
                }
            }
        }
        return count(ar.begin(),ar.end(),true);
    }
    
   
};