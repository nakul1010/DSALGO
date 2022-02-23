// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) 
	{
	    
	    long z = 1, o = 1, mod = 1000000007 ;
        for(int i = 2; i <= n; i++) 
        {
            long temp = z;
            z = (z + o) % mod;
            o = temp % mod;
        }
        return (z + o) % mod;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends