class Solution {
public:
    vector<vector<int>>ans;
    
    void solve(vector<int>& arr,int i,int n,unordered_set<string> st,vector<int> vec)
    {
        if(i==n)
        {
            string str = "";
            
            for(int j=0;j<vec.size();j++)
                str += to_string(vec[j]);
            
            if(st.find(str)==st.end())
                ans.push_back(vec);
            st.insert(str);
            return;
        }
        
        //excl
        solve(arr,i+1,n,st,vec);
        
        //incl
        vec.push_back(arr[i]);
        solve(arr,i+1,n,st,vec);
    }
    
    vector<vector<int>> subsets(vector<int>& arr) 
    {
        int n = arr.size();
        unordered_set<string>st;
        vector<int>vec;
        
        solve(arr,0,n,st,vec);
        
        return ans;
    }
};