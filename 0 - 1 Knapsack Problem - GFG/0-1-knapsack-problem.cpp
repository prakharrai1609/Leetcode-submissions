// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
int dp[1001][1001];
   int knapsack(int W, int wt[], int val[], int n)
   {    if(n==0||W==0)
         return 0;
       if(dp[n][W]!=-1)
        return dp[n][W]; 
       int inc=0;int exc=0;
       if(W-wt[n-1]>=0)
       {
           inc=val[n-1]+knapsack(W-wt[n-1],wt,val,n-1);
       }
       exc=knapsack(W,wt,val,n-1);
       return dp[n][W]=max(inc,exc);
   }
   int knapSack(int W, int wt[], int val[], int n) 
   {      memset(dp,-1,sizeof(dp));
       return knapsack(W,wt,val,n);
   }


};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends