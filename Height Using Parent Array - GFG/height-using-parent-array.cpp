// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findHeight(int n, int arr[])
    {
        vector<int>adj[n];
        int root = -1, cnt=0;
        for(int i=0; i<n; i++)
        {
            if(arr[i]==-1)
                root = i;
            else
                adj[arr[i]].push_back(i);
        }
        
        queue<int>q;
        q.push(root);
        q.push(-1);
        
        while(q.empty()==false)
        {
            int curr = q.front();
            q.pop();
            if(curr==-1)
            {
                cnt++;
                q.push(-1);
                curr = q.front();
                q.pop();
                if(curr==-1) break;
            }
            
            for(auto i : adj[curr])
            {
                q.push(i);
            }
            
            // for(int i=0;i<n;i++)
            // {
            //     if(arr[i]==curr)
            //     {
            //         q.push(i);
            //         arr[i] = -1;
            //     }   
            // }
        }
        return cnt;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.findHeight(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends