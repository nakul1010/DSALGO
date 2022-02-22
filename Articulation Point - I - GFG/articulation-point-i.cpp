// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
 public:
int NIL = -1;
vector<int>ans;
void APUtil(vector<int>adj[], int u, bool visited[], int disc[], int low[], int parent[], bool ap[]) 
{ 
	static int time_ = 0; 

	int children = 0; 
	visited[u] = true; 
	disc[u] = low[u] = time_++; 
	vector<int>::iterator i; 
	for (i = adj[u].begin(); i != adj[u].end(); ++i) 
	{ 
		int v = *i; // v is current adjacent of u 

		if (!visited[v]) 
		{ 
			children++; 
			parent[v] = u; 
			APUtil(adj, v, visited, disc, low, parent, ap); 

			low[u] = min(low[u], low[v]);

			if (parent[u] == NIL && children > 1) 
				ap[u] = true; 

			if (parent[u] != NIL && low[v] >= disc[u]) 
			    ap[u] = true; 
		} 
		else if (v != parent[u])
			low[u] = min(low[u], disc[v]); 
	} 
} 

vector<int> articulationPoints(int V, vector<int>adj[]) 
{
	bool visited[V];
	int disc[V];
	int low[V];
	int parent[V];
	bool ap[V];

	for(int i = 0; i < V; i++) 
	{ 
		parent[i] = NIL; 
		visited[i] = false; 
		ap[i] = false; 
	} 

	for (int i = 0; i < V; i++) 
		if (visited[i] == false) 
			APUtil(adj, i, visited, disc, low, parent, ap); 

	for (int i = 0; i < V; i++) 
	{
	    if (ap[i] == true) 
		{
		    ans.push_back(i);
		}
	}
	if(ans.size()==0)
	    ans.push_back(-1);
	return ans;
}
};

// { Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends