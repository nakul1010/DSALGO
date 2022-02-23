// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.

bool isSafe(bool graph[101][101], vector<int>&colors, int i, int c)
{
    for(int j=0;j<101;j++)
    {
        if(graph[i][j]==1 && colors[j]==c)
        {
            return false;
        }
    }
    return true;
}

bool solve(bool graph[101][101], vector<int>&colors, int i, int m, int V)
{
    if(i>=V)
    {
        return true;
    }
    for(int c=1;c<=m;c++)
    {
        if(isSafe(graph, colors, i, c))
        {
            colors[i] = c;
            if(solve(graph, colors, i+1, m, V))
                return true;
            colors[i] = -1;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    vector<int>colors(V,-1);
    int i=0;
    return solve(graph, colors, i, m, V);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends