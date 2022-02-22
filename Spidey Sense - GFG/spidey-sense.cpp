// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

    public:
    
    bool isPossible(int x1,int y1,int x,int y)
    {
        if(x1<0 || y1<0 || x1>=x || y1>=y)
            return false;
        return true;
    }
    
    vector<vector<int> > findDistance(vector<vector<char> >& matrix, int n, int m) 
    {
        vector<vector<int>> ans( n , vector<int> (m,INT_MAX));
        queue<pair<int,int>>q;
        pair<int,int>var;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='W')
                {
                    ans[i][j] = -1;
                }
                else if(matrix[i][j]=='B')
                {
                    ans[i][j] = 0;
                    q.push(make_pair(i,j));
                }
            }
        }
        
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        
        while(q.empty()==false)
        {
            var = q.front();
            q.pop();
            int x =var.first, y=var.second;
            
            for(int k=0;k<4;k++)
            {
                int new_x = x + dx[k], new_y = y + dy[k];
                if(isPossible(new_x,new_y,n,m)==false)
                {
                    continue;
                }
                else if(matrix[new_x][new_y]=='O' &&  ans[new_x][new_y] > ans[x][y] + 1)
                {
                    ans[new_x][new_y]=ans[x][y] + 1;
                    q.push(make_pair(new_x,new_y));
                }
                // cout<<"x : "<<new_x<<"   y : "<<new_y<<endl;    
            }
        }
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(ans[i][j]==INT_MAX)
                {
                    ans[i][j]=-1;
                }
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
    while(t--)
    {
    	int M,N;
        cin>>M;
        cin>>N;

        vector<vector<char> > matrix(M);
        for(int i=0; i<M; ++i)
        {
            matrix[i].resize(N);
            for (int j = 0; j < N; ++j)
                cin>>matrix[i][j];
        }

        vector<vector<int> >result;
        Solution obj;
        result = obj.findDistance(matrix, M,N); 
        for(int i=0; i<M; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout<<result[i][j]<<" ";
            cout<<"\n";
        }
    }

    return 0;
}  // } Driver Code Ends