class Solution {
public:
    int maxProfit(vector<int>& arr) 
    {
        int n = arr.size();
        // int dp[n];
        // for(int i=0;i<n;i++)
        // {
        //     dp[i]=0;
        // }
        int max_val = arr[n-1];
        int ans = 0;
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]>max_val)
                    max_val = arr[i];
            
            // dp[i] = max(dp[i+1] , );
            ans = max(ans,max_val - arr[i]);
        }
        return ans;
    }
};