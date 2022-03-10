class FindSumPairs 
{
public:
    unordered_map<int,int>mp1 , mp2;
    vector<int>nums1,nums2;
    FindSumPairs(vector<int>& a1, vector<int>& a2) 
    {
        nums1 = a1, nums2 = a2;
        for(int i=0; i<a1.size(); i++)
            mp1[a1[i]]++;      
        for(int i=0; i<a2.size(); i++)
            mp2[a2[i]]++;      
        nums2 = a2;
    }
    
    void add(int index, int val) 
    {
        mp2[nums2[index]]--;//remove freq of prev number
        nums2[index] += val;
        mp2[nums2[index]]++;//add freq of new generated number
    }
    
    int count(int tot)
    {
        int cnt = 0;
        for(auto it : mp1)
        {
            auto [num,freq] = it;
            int find = tot - num;
            if(mp2[find])
                cnt += freq * mp2[find]; //freq*freq
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */