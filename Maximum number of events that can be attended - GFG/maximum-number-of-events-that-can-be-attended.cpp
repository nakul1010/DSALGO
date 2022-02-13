// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    
    int maxEvents(int start[], int end[], int n)//n2 Solution
    {
        vector< pair<int,int> >vec;
        for(int i=0;i<n;i++)
            vec.push_back(make_pair(start[i],end[i]));
        
        sort(vec.begin(),vec.end());
        
    
        // for(int i=0;i<n;i++)
        // {
        //     cout<<vec[i].first<<" : "<<vec[i].second<<endl;
        // }
        
        priority_queue<int, vector<int>,greater<int>> pq; // pq with min end times
        int i=0, day=1, meet=0;
        while(i<n || pq.size())
        {
            while(pq.empty()==false && pq.top()<day)//can't attend
                pq.pop();
                
            while((i<n) && (vec[i].first==day))
            {
                pq.push(vec[i].second);
                i++;
            }
            
            day++;
            
            if(pq.size())
            {
                meet++;
                pq.pop();
            }
        }
        
        return meet;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];

        Solution ob;
        cout << ob.maxEvents(start,end,N) << endl;
    }
    return 0;
}  // } Driver Code Ends