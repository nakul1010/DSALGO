// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    string chooseandswap(string str)
    {
    	int n = str.length();
    	
    	for(int i=0;i<n-1;i++)
    	{
    		set<char>s;//stores from small to large 
    		set<char>::iterator itr;
    		//insert all in set
    		for(int j=i+1;j<n;j++)
    		{
    			if(str[j]!=str[i])
    				s.insert(str[j]);
    		}
    		
    		//delete prev from set
    		for(int j=i-1;j>=0;j--)
    		{
    			if(s.find(str[j])!=s.end())
    				s.erase(str[j]);
    		}
    			
    		if(s.empty()==false)
    		{
    			itr = s.begin();
    			char replace1 = *itr;
    			char replace2 = str[i];
    			
    			if(replace1 < replace2)	
    			{
    				for(int k=0;k<n;k++)
    				{
    					if(str[k]==replace1)
    						str[k] = replace2;
    					else if(str[k]==replace2)
    						str[k] = replace1;
    				}
    				return str;	
    			}
    		}
    	}
    	return str;
    }
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends