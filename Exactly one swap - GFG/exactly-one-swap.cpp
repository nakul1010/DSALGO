// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long countStrings(string str)
    {
        long long ans = 0;
        
        int n = str.size();
        int freq[27]= {0};
        memset(freq,0,sizeof(freq));
        
        for(auto &ch : str)
        {
            // cout<<ch;
            freq[int(ch-'a')]++;
        }
        
        
        for(auto &ch : str)
        {
            // cout<<"ch : "<<ch<<"     freq : "<<freq[ch]<<endl;
            ans += abs(n - freq[ch-'a']);
        }
        // cout<<"ans : "<<ans<<endl;
        ans /= 2;
        
        for(auto &ch : str)
        {
            if(freq[ch-'a']>=2)
            {
                ans++;
                break;
            }
        }
        return ans;
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution ob;
        long long ans = ob.countStrings(S);
        cout<<ans<<endl;
    }
    return 0;
}   // } Driver Code Ends