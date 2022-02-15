class Solution {
public:
    int singleNumber(vector<int>& arr) 
    {
        int n = arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
            mp[arr[i]]++;
        
        for(int i=0;i<n;i++)
        {
            int x = mp[arr[i]];
            if(x==1)
                return arr[i];
        }
        return -1;
    }
    
};