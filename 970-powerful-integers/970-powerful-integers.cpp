class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) 
    {
        vector<int>max_x, max_y,ans;
        if(bound==0)
            return ans;
        
        unordered_set<int>s;
        
        int product = 1;
        
        
        if(x!=1)
        {
            while(product <= bound)
            {
                // s.insert(product);
                max_x.push_back(product);
                product = product * x;
            } 
        }
        else
            max_x.push_back(1);
        
        if(y!=1)
        {
            product = 1;
            while(product <= bound)
            {
                max_y.push_back(product);
                product = product * y;
            }
        }
        else
        {
            max_y.push_back(1);
        }
        
        for(int i=0; i<max_x.size(); i++)
        {
            for(int j=0;j<max_y.size();j++)
            {
                if(max_x[i]+max_y[j] <= bound)
                    s.insert(max_x[i]+max_y[j]);
            }
        }    
        
        
        for(auto it : s)
        {
            ans.push_back(it);
        }
        return ans;
    }
};