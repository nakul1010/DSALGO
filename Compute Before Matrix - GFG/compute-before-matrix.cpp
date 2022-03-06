// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    bool check(int i,int j,int row,int col)
    {
        if(i<0 ||j<0 || i>=row || j>=col)
            return false;
        return true;
    }
    
    vector<vector<int>> computeBeforeMatrix(int row, int col, vector<vector<int>> after)
    {
        vector<vector<int>>before(row, vector<int>(col,0));
        
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                before[i][j] = after[i][j];
                if(check(i,j-1,row,col))
                {
                    before[i][j] -= after[i][j-1];
                }
                if(check(i-1,j,row,col))
                {
                    before[i][j] -= after[i-1][j];
                }
                if(check(i-1,j-1,row,col))
                {
                    before[i][j] += after[i-1][j-1];
                }
            }
        }
        
        return before;
        
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M;
        cin>>N>>M; 
        vector<vector<int>> after(N,vector<int>(M));
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>after[i][j];
            }
        } 
        Solution obj;
        vector<vector<int>> before=obj.computeBeforeMatrix(N,M,after); 
        for(int i=0;i<before.size();i++){
            for(int j=0;j<before[i].size();j++){
                cout<<before[i][j]<<' ';
            } 
            cout<<endl;
        }
    }
}  // } Driver Code Ends