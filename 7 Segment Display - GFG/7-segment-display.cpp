// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    string sevenSegments(string S, int N) 
    {
        S = S.substr(0, N);

        int values[10] = {6,2,5,5,4,5,6,3,7,5};
        int insert_values[] = {0,1};
        int n = N;
        
        int wt = 0;
        for(int i=0; i<S.size(); i++)
        {
            wt += values[int(S[i]-'0')];
        }
        // cout<<"wt : "<<wt<<endl;
        string str = "";
        
        for(int i=N-1 ;i>=0; i--)
        {
            for(int j=0; j<10; j++)
            {
                if( (wt - values[j] >= 2*i) && (wt - values[j] <= 7*i))
                {
                    str += (j+'0');
                    wt -= values[j];
                    break;
                }
            }
        }
        
        return str;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        string S;
        cin>>S;

        Solution ob;
        cout << ob.sevenSegments(S,N) << endl;
    }
    return 0;
}  // } Driver Code Ends