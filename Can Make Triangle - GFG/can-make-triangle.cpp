// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    
    bool check(int a, int b, int c)
    {
        if(a+b>c && a+c>b && b+c>a)
            return true;
        return false;
    }
    
    vector<int> canMakeTriangle(vector<int> arr, int n)
    {
        vector<int>ans;
        int i = 3 , a = arr[0], b = arr[1], c = arr[2];
        
        if(check(a,b,c))
            ans.push_back(1);
        else
            ans.push_back(0);
            
        while(i<n)
        {
            a = b;
            b = c;
            c = arr[i];
            if(check(a,b,c))
                ans.push_back(1);
            else
                ans.push_back(0);
            i++;
        }
        
        return ans;
    }
}; 

// { Driver Code Starts.
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++)
            cin>>A[i];
        Solution ob;
        auto ans = ob.canMakeTriangle(A, N);
        for(int i=0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << endl;
        
    }

    return 0; 
}   // } Driver Code Ends