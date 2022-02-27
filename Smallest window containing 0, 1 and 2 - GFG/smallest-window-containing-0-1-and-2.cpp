// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string str) 
    {
        int cnt0=0,cnt1=0,cnt2=0;
        int n = str.length(), i=0,j=0, ans = INT_MAX;
        
        while(i<n)
        {
            if(str[i]=='0')
                cnt0++;
            if(str[i]=='1')
                cnt1++;
            if(str[i]=='2')
                cnt2++;
            
            if(cnt0>0 && cnt1>0 && cnt2>0 && i<n && j<n)
                ans = min(ans, abs(i-j)+1);
            
            while(cnt0>0 && cnt1>0 && cnt2>0)
            {
                if(cnt0>0 && cnt1>0 && cnt2>0 && i<n && j<n)
                    ans = min(ans, abs(i-j)+1);
                    
                if(str[j]=='0')
                    cnt0--;
                if(str[j]=='1')
                    cnt1--;
                if(str[j]=='2')
                    cnt2--;
                j++;
            }
            
            if(cnt0>0 && cnt1>0 && cnt2>0 && i<n && j<n)
                ans = min(ans, abs(i-j)+1);
            i++; 
        }
        
        
        if(cnt0>0 && cnt1>0 && cnt2>0 && i<n && j<n)
            ans = min(ans, abs(i-j)+1);
            
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}  // } Driver Code Ends