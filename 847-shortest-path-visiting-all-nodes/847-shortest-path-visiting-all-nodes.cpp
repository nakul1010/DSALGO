class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        if(n==1)
            return 0;
        
        int all = (1 << n) - 1;//all visitted 16 - 1 = 15 or 1000 - 1 = 1111
        // cout<<all;//15
        
        queue< pair<int, pair<int,int> > >q;// u , dist, mask
        set<pair<int,int>>vis;
        
        for(int i=0; i<n; i++)
        {
            int mask = (1<<i);
            q.push({i,{0,mask}});
            vis.insert({i,mask});
        }   
        
        while(q.empty()==false)
        {
            int vertex = q.front().first;
            int dist = q.front().second.first;
            int src_mask = q.front().second.second;
            q.pop();
            
            for(auto node: graph[vertex])
            {
                int new_mask =  (src_mask | (1<<node));//0001 | 0010 = 0011
                if(new_mask == all)
                    return dist + 1;
                else if(vis.find({node, new_mask}) != vis.end())
                    continue;
                q.push({node,{dist+1,new_mask}});
                vis.insert({node,new_mask});
            }
            
        }
        return -1;
    }
};