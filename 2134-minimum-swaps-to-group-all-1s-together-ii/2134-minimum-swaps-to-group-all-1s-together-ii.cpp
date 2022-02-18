class Solution {
public:
    int minSwaps(vector<int>& nums) 
    {
        int n = nums.size(), min_swaps=0 , cnt_one=0;
        
        for(int i=0; i<n; i++)
        {
            if(nums[i]==1)
                cnt_one++;
        }
        
        if(cnt_one == 0)
            return 0;
        
        // for(int i=0;i<n;i++)
        // {
        //     nums.push_back(nums[i]);
        // }
        nums.insert(nums.end(), nums.begin(), nums.end());//append
        
        int swaps = n, left = 0, right = 0, one = 0;
        
        while(right<2*n)
        {
            if(nums[right]==1)
                one++;
            if(abs(right-left+1) == cnt_one)//sliding window window size = right-left+1
            {
                swaps = min(swaps, cnt_one-one);
                // cout<<"left : "<<left<<"     right : "<<right<<"    swaps : "<<swaps<<endl;
             
                if(nums[left]==1)
                    one--;
                left++;
            }
            right++;
        }
        return swaps;
    }
};