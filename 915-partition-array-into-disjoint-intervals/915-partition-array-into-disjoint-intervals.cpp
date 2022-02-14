class Solution {
public:
    int partitionDisjoint(vector<int>& arr) 
    {
        int size = INT_MAX;
        int n = arr.size();
        
        int small_left[n];
        int small_right[n];
        
        int curr_small = INT_MAX;
        for(int i=n-1;i>=0;i--)
        {
            curr_small = min(curr_small, arr[i]);
            small_left[i] = curr_small; 
        }
        
        curr_small = INT_MAX;
        for(int i=0;i<n;i++)
        {
            curr_small = min(curr_small, arr[i]);
            small_right[i] = curr_small; 
        }
        
        int max_curr = -1;
        for(int i=0;i<n-1;i++)
        {
            max_curr = max(arr[i],max_curr);
            if(max_curr <= small_left[i+1])
                size = min(size, (i+1));
        }
        
//         max_curr = -1;
//         for(int i=n-1;i>0;i--)
//         {
//             max_curr = max(arr[i],max_curr);
//             if(max_curr <= small_right[i-1])
//                 size = min(size, (n-i));
//         }
        
        return size;
    }
};