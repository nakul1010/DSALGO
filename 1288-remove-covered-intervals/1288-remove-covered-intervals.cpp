class Solution {
public:
    
    static bool compare(vector<int>v1 , vector<int>v2)
    {
        if(v1[0]!=v2[0])
            return v1[0]<v2[0];
        return v1[1]>v2[0];
        
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end(),compare);
        stack< vector<int> >st;
        
        for(auto vec: intervals)
        {
            cout<<vec[0]<<" : "<<vec[1]<<endl;
        }
        
        st.push(intervals[0]);
        
        for(int i=1;i<intervals.size(); i++)
        {
            vector<int>top = st.top();
            vector<int>curr = intervals[i];
            
            if(curr[0]>=top[0] && curr[1]<=top[1])
                continue;
            else
                st.push(curr);
            
        }
        return st.size();
    }
};