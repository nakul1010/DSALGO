// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++


struct myQueue
{
  int cellno;  
  int d;
};

class Solution
{
public:
//___________________________________________________________________________________________
    int min_dice_throw(int N,int moves[],bool visited[])
    {
        visited[1] = true;
        queue<myQueue>q;
        q.push({1,0});
        myQueue curr;
        while(q.empty()==false)
        {
            
            curr = q.front();
            q.pop();
            // cout<<"Hi"<<endl;
            if(curr.cellno == 30)
            {
                return curr.d;
            }
                
            for(int i=curr.cellno+1; i<=(curr.cellno+6)&&i<=30;i++)//<N for 30,31...
        	{
        	   // cout<<i<<endl;
        	    myQueue e;
        		if(visited[i]==false)
        		{
        			visited[i]=true;
        			if(moves[i]==-1)
        				e.cellno = i;
        			else
        				e.cellno = moves[i];
        			e.d = curr.d +1;
        			q.push(e);
        			if(e.cellno == 30)
                    {
                        return e.d;
                    }
                    
    			}
    		}
        }
        
        return -1;
    }
//___________________________________________________________________________________________
    int minThrow(int N, int arr[])
    {
        int moves[33];
        bool visited[33] = {false};
        int i;
        for(i=1;i<31;i++)
            moves[i]=-1;
        
        for(i=0;i<2*N;i++)
        {
            moves[arr[i]] = arr[i+1];
            i++;
        }
        
        int ans = min_dice_throw(N,moves,visited);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends