// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 


 // } Driver Code Ends
class Solution
{
    public:
    
    int dp[101][101];
    
    int LCS(string str1,int n1,string str2,int n2)
    {
        if(n1<0 || n2<0)
            return 0;
        if(dp[n1][n2]!=-1)
            return dp[n1][n2];
        
        if(str1[n1]==str2[n2])
            return dp[n1][n2] = 1 + LCS(str1,n1-1,str2,n2-1);
        
        return dp[n1][n2] = max(LCS(str1,n1,str2,n2-1), LCS(str1,n1-1,str2,n2));
    }
    int build_bridges(string str1, string str2)
    {
        memset(dp,-1,sizeof(dp));
        int n1=str1.length(), n2=str2.length();
        
        return LCS(str1,n1-1,str2,n2-1);
    }
};

// { Driver Code Starts.
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        string str1,str2;
        cin >> str1 >> str2;
        Solution obj;
        cout<<obj.build_bridges(str1,str2)<<endl;
    } 
    return 0;
} 
  // } Driver Code Ends