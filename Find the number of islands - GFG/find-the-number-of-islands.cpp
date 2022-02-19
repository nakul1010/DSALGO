// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool visit[501][501];
	int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
	int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 }; 
	
    void DFS(vector<vector<char>>&mat,int row,int col,int x, int y)//if not &mat TLE
    {
        if(x<0 || y<0 || x>=row || y>=col)
            return;
        if(mat[x][y]=='0' || visit[x][y] == true)
            return;
        visit[x][y] = true;
        for(int i=0;i<8;i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            DFS(mat, row, col, new_x, new_y);
        }
    }
    
    int numIslands(vector<vector<char>>& mat) 
    {
        //get intialize method
        int row=mat.size(), col=mat[0].size();
        memset(visit, false, sizeof(visit));
        int islands = 0;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(mat[i][j]=='1' && visit[i][j]==false)
                {
                    islands++;
                    DFS(mat, row, col, i, j);
                }
            }
        }   
        return islands;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends