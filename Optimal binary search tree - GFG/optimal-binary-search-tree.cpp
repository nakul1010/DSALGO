// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int optimalSearchTree(int keys[], int freq[], int n)
    {
    	int dp[n][n];
    	memset(dp,0,sizeof(dp));
    	
    	int sum = 0;
    	for(int i=0;i<n;i++)
    		sum += freq[i];
    	
    	for(int g=0;g<n;g++)
    	{
    		for(int i=0,j=g;j<n;i++,j++)//j<n imp to remember
    		{
    			if(g==0)
    			{
    				dp[i][j] = freq[i];
    			}
    			else if(g==1)
    			{
    				int left = dp[i][j-1] + 2 *(dp[i+1][j]);//a'+2b'
    				int right = 2*(dp[i][j-1]) + dp[i+1][j];//2b'+a'
    				dp[i][j] = min(left,right);
    			}
    			else
    			{				
    				sum = 0;
    				for(int m=i;m<=j;m++)
    					sum += freq[m];
    
    				dp[i][j] = INT_MAX;
    				for(int k=i;k<=j;k++)//k=i an not zero remember
    				{
    					int left,right,total;
    					left = right = total = 0;
    					if(k-1>=0)
    						left = dp[i][k-1];
    					if(k+1<n)
    						right = dp[k+1][j];
    					total = left + right + sum;
    					dp[i][j] = min(dp[i][j], total);
    				}
    			}
    		}
    	}
    	return dp[0][n-1];

    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int keys[n];
        for(int i=0;i<n;i++)cin>>keys[i];
        int freq[n];
        for(int i=0;i<n;i++)cin>>freq[i];
        Solution ob;
        cout<<ob.optimalSearchTree(keys, freq, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends