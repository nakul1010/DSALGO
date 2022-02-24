// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

int dp[501];
//____________________________________________________________________________________________________________________________________________________________
bool isPalindrome(string str,int s,int e)
{
	int i,j;
	for(i=s,j=e; i<=e && j>=s; i++,j--)//wrong here <= & >=
	{
		if(str[i]!=str[j])
			return false;
	}
	return true;
}
//____________________________________________________________________________________________________________________________________________________________
int palindromic_pats(string str,int index, int n)
{
	if(str.size()==index)
	{
		return 0;
	}
	
	if(dp[index]!=-1)
		return dp[index];
		
	int ans=INT_MAX,temp=0;
	for(int i=index;i<str.size();i++)
	{
		if(isPalindrome(str,index,i))
		{
			temp = 1 + palindromic_pats(str,i+1,n);
			ans = min(ans,temp);
		}
	}
	return dp[index] =  ans;
}
//____________________________________________________________________________________________________________________________________________________________
int palindromicPartition(string str)
{
    memset(dp,-1,sizeof(dp));
    int n = str.length();
    return palindromic_pats(str,0,n)-1;
}
//____________________________________________________________________________________________________________________________________________________________
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends