class Solution {
public:
    bool canArrange(vector<int>& arr, int k) 
    {
        unordered_map<int,int>mp;
        int n = arr.size(), directly_divisible=0;
        for(int i=0;i<n;i++)
        {
            // cout<<arr[i]<<" : "<<arr[i]%k<<" : "<<(arr[i]%k+k)%k<<endl;
            mp[(arr[i]%k+k)%k]++;
            
        }
        if(mp[0]%2 != 0)
            return false;
        cout<<endl;
        for(int i=1;i<k;i++)
        {
            // cout<<"i : "<<i<<"   mp[i] : "<<mp[i]<<"     mp[k-i] : "<<mp[k-i]<<endl;
            if(mp[i]!=mp[k-i])
                return false;
        }
        return true;
    }
};