// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    double slope(int x1, int y1, int x2, int y2)
    {
        if(x2-x1 == 0)//random valuefor infinite slope
            return 122;
        return (double)((double)y2 - (double)y1) / ((double)x2 - (double)x1);
    }
    
    int mostBalloons(int n, pair<int, int> arr[]) 
    {
        if(n<3)
            return n;
            
        map<double, int>mp;
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            int curr_max = 0, duplicate=1;
            for(int j=i+1; j<n; j++)
            {
                if(arr[i]==arr[j])
                {
                    duplicate++;
                }
                else
                {
                    double slope_ans = slope(arr[i].first, arr[i].second,arr[j].first, arr[j].second);
                    mp[slope_ans]++;
                    // curr_max = max(curr_max, mp[slope_ans]);    
                }
            }
            ans = max(ans, duplicate);
            for (auto p : mp)
            {
                ans = max(ans, p.second+duplicate);    
            }
            mp.clear();
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        pair<int, int> arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i].first;
        }
        for (int i = 0; i < N; i++) {
            cin >> arr[i].second;
        }
        Solution ob;
        cout << ob.mostBalloons(N, arr) << endl;
    }
}  // } Driver Code Ends