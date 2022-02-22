// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    vector<string>vec;
    void Rat_maze(vector<vector<int>>&mat,int n,int i,int j,string str)
    {
        if(i==n-1 && j==n-1)
        {
            vec.push_back(str);
            return;
        }
        if( mat[i][j] == 0)
            return;
        mat[i][j] = 0;
        
        if(i+1<n && mat[i+1][j]==1)
        {
            str = str + "D";
            Rat_maze(mat,n,i+1,j,str);
            str.pop_back();
        }
        if(i-1>=0 && mat[i-1][j]==1)
        {
            str = str + "U";
            Rat_maze(mat,n,i-1,j,str);
            str.pop_back();
        }
        if(j+1<n && mat[i][j+1]==1)
        {
            str = str + "R";
            Rat_maze(mat,n,i,j+1,str);
            str.pop_back();
        }
        if(j-1>=0 && mat[i][j-1]==1)
        {
            str = str + "L";
            Rat_maze(mat,n,i,j-1,str);
            str.pop_back();
        }
        
        mat[i][j] = 1;
    }
    
    vector<string> findPath(vector<vector<int>> &mat, int n) 
    {
        // string
        if(mat[0][0]==0)
        {
            vec.push_back("-1");
            return vec;
        }
            
        Rat_maze(mat,n,0,0,"");
        sort(vec.begin(),vec.end());
        return vec;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends