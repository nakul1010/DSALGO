// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long countPairs(int n, int x, vector<int> numbers)
    {
        long long cnt = 0;
        
        string final = to_string(x);
        
        unordered_map<string, int>mp;
        
        for(int i=0;i<n;i++)
        {
            mp[to_string(numbers[i])]++;
        }
        
        for(int i=0;i<n;i++)
        {
            string curr = to_string(numbers[i]);
            
            if(curr.size()>final.size())
                continue;
            else if(curr.size()==final.size())
            {
                continue;
                // cout<<"curr : "<<curr<<"    final : "<<final<<endl;
                // if(curr==final)
                //     cnt++;
            }
            
            
            else
            {
                string sub = final.substr(0, curr.size());
                string find = final.substr(curr.size());
                
                // cout<<"sub : "<<sub<<"    find : "<<find<<"    mp[find] : "<<mp[find]<<endl;
                if(curr == sub)
                {
                    if(find == sub && mp[find]>=1)
                        cnt += (mp[find] - 1);
                    else
                        cnt += mp[find];
                }
            }
        }
        
        return cnt;
    }
}; 

// { Driver Code Starts.
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int N,X;
        cin>>N>>X;
        vector<int> numbers(N);
        for(int i=0;i<N;i++)
            cin>>numbers[i];
        Solution ob;
        long long ans = ob.countPairs(N, X, numbers);
        cout<<ans<<endl;
        
    }

    return 0; 
}  // } Driver Code Ends