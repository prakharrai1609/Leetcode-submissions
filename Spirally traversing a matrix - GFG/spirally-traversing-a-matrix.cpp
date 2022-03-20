// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        int fr = 0, lr = r - 1, fc = 0, on = 1, lc = c - 1, inv = 0;
        // on == 1 ? horizontal : vertical
        // inv == 1 ? right to left or bottom to top ? o/w
        //  h == 1 : left to right
        //  v == 1 : top to bottom
        
        vector<int> ans;
        
        while (fr <= lr and fc <= lc) {
            if (on and !inv) 
            {
                int i = fr++;
                for (int j = fc; j <= lc; j++) 
                    ans.push_back(matrix[i][j]);
                on = 0, inv = 0;
            } 
            else if (on and inv)
            {
                int i = lr--;
                for (int j = lc; j >= fc; j--) 
                    ans.push_back(matrix[i][j]);
                on = 0, inv = 1;
            }
            else if (!on and !inv) 
            {
                int j = lc--;
                for (int i = fr; i <= lr; i++)
                    ans.push_back(matrix[i][j]);
                on = 1, inv = 1;
            }
            else 
            {
                int j = fc++;
                for (int i = lr; i >= fr; i--)
                    ans.push_back(matrix[i][j]);
                on = 1, inv = 0;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends