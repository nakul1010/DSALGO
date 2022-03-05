class Solution {
public:
    int dp[20001];
    int  solve(vector<int>& arr,int i)
    {
        if(i>=arr.size())
            return 0;
        if(dp[i] != -1)
            return dp[i];
        
        
        int curr_sum = arr[i];
        int curr_val = arr[i];
        int index = i+1;
        
        while(index<arr.size() && arr[index] == curr_val)
        {
            curr_sum += arr[i];
            index++;
        }
        
        int next_index = index;
        while(index<arr.size() && arr[index] == curr_val+1)
        {
            index++;
        }
        
        // cout<<"i : "<<i<<"   index : "<<index<<"     next_index : "<<next_index<<"    curr_sum : "<<curr_sum<<endl;
        int include_curr_index = curr_sum + solve(arr, index);
        int exclude_curr_index = solve(arr, next_index);
        
        return dp[i] = max(include_curr_index, exclude_curr_index);
    }
    
    int deleteAndEarn(vector<int>& arr) 
    {
        memset(dp, -1, sizeof(dp));
        sort(arr.begin(),arr.end());
        return solve(arr,0);    
    }
};