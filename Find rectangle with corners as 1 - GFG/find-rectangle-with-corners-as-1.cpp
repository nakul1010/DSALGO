// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
#include <unordered_map>
#include <unordered_set>
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool ValidCorner(const vector<vector<int> >& matrix)
    {
        for(int r1=0; r1<matrix.size(); r1++)
        {
            for(int r2=r1+1; r2<matrix.size(); r2++)
            {
                int cnt = 0;
                for(int c1=0;c1<matrix[r1].size(); c1++)
                {
                    for(int c2=c1+1;c2<matrix[r1].size(); c2++)
                    {
                        if(matrix[r1][c1]==1 && matrix[r2][c1]==1 && matrix[r1][c2]==1 && matrix[r2][c2]==1)
                        {
                            // cout<<"\nr1 : "<<r1<<"   c1 : "<<c1<<"    r2 : "<<r2<<"    c2 : "<<c2<<endl;
                            return true;
                        }
                            
                    }
                }
                    
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int row, col;
        cin>> row>> col;

        vector<vector<int> > matrix(row);
            
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        Solution ob;
        if (ob.ValidCorner(matrix)) 
            cout << "Yes\n"; 
        else
            cout << "No\n"; 
    }

    return 0;
} 


  // } Driver Code Ends