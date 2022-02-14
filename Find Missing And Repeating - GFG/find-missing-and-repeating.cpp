// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) 
    {
        int *store = new int[2];
        unordered_set<int>s;
        for(int i=0;i<n;i++)
        {
            if(s.empty()==false && s.find(arr[i])!=s.end())
            {
                store[0] = arr[i];
            }
            s.insert(arr[i]);
        }
        
        for(int i=1;i<=n;i++)
        {
            if(s.find(i)==s.end())
            {
                store[1] = i;
                break;
            }
        }
        return store;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends