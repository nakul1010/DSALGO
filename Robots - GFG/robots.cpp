// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    string moveRobots(string s1, string s2)
    {
        if(s1.length()!=s2.length())
            return "No";
        int n = s2.length(), b_cnt=0, a_cnt=0, i=0, j=0; 
        
        while(i<n && j<n)
        {
            while(i<n && s1[i]!='A' && s1[i]!='B')
                i++;
            while(j<n && s2[j]!='A' && s2[j]!='B')
                j++;
            
            if(s1[i]!=s2[j])
                return "No";
            
            if(s1[i]=='A' && i<j)
                return "No";
                
            if(s1[i]=='B' && i>j)
                return "No";
            i++,j++;
        }
        
        while(i<n)
        {
            if(s1[i]=='A' || s1[i]=='B')
                return "No";
            i++;
        }
        
        while(j<n)
        {
            if(s2[j]=='A' || s2[j]=='B')
                return "No";
            j++;
        }
        
        return "Yes";
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin >> s1;
        cin >> s2;
        
        Solution ob;
        cout << ob.moveRobots(s1, s2) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends