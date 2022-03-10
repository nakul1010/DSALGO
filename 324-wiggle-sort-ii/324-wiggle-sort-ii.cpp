class Solution {
public:
    void wiggleSort(vector<int>& nums) 
    {
        vector<int>ans = nums;
        sort(ans.begin(),ans.end());
        int n = nums.size();
        int j = n-1;
        
        //put max elements
        for(int i=1; i<n; i=i+2,j--)
        {
            nums[i] = ans[j];
        }
        
        for(int i=0; i<n; i=i+2,j--)
        {
            nums[i] = ans[j];
        }
        
        
    }
};