class Solution {
public:
    int findFinalValue(vector<int>& arr, int original) 
    {
        unordered_map<int,int>mp;
        unordered_map<int,int>::iterator it;
        
        for(int i=0;i<arr.size();i++)
            mp[arr[i]]++;
        
        
        while(mp.find(original)!=mp.end())
        {
            // it = mp.find(original);
            // it->second = it->second - 1;
            // if(it->second <= 0)
            //     mp.erase(original);
            original = original + original;
            // mp[original]++;
        }
        return original;
    }
};