// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string str)
    {
    	int start=0,n=str.size();
    	int dp[n][n];
    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<n;j++)
    		{
    			dp[i][j]=0;
    		}
    	}
    	
    	//USE GAP STRATEGY INSTEAD
    	int max_length = -1;
    	//for substring of length 1
    	max_length = 1;
    	for(int i=0; i<n; i++)
    	{
    		dp[i][i] = 1;
    	}
    	
    	//for substring of length 2
    	for(int i=0;i<n-1;i++)//IMP <n-1
    	{
    		if(str[i]==str[i+1])
    		{
    			max_length=2;
    			if(start==0)
    			    start = i;
    			dp[i][i+1]=1;
    		}
    	}
    	
    	//for substring of length >= 3
    	for(int k=3;k<=n;k++)
    	{
    		for(int i=0;i<n-k+1;i++)
    		{
    			int j = i+k-1;
    			
    			if(str[i]==str[j] && dp[i+1][j-1]==1)
    			{
    				dp[i][j]=1;
    				
    				if(k==max_length && start > i)
    				    start = i;
    				
    				if(k>max_length)
    				{
    				    // cout<<"start : "<<start<<endl;
    					start = i;
    					max_length = j-i+1;//or k
    				}
    			}
    			else
    			{
    				dp[i][j]=0;
    			}
    		}
    	}
    	
    	
    	int low = start, high = start + max_length - 1;
    	string ans = "";
    	for (int i = low; i <= high; ++i)
    		ans += str[i];
        return ans;
    }
};

// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends