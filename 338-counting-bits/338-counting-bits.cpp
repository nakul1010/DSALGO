class Solution {
public:
    vector<int> countBits(int n) 
    {
        vector<int>ans;
        ans.push_back(0);
        if(n==0)
            return ans;
        
        queue<int>q;
        q.push(1);
        
        while(q.empty()==false)
        {
            int front = q.front();
            q.pop();
            ans.push_back(front);
            if(ans.size() == n+1)
                break;
            
            q.push(front);
            q.push(front+1);
        }
        
        
        return ans;
    }
};