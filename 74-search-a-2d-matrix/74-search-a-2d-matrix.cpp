class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) 
    {
        int row = arr.size(), col = arr[0].size();
        
        int get_row = -1, start = 0, end = row-1, prev_mid=-1,mid;
        
        while(start<=end)
        {
            int mid = (start+end)/2;
            
            if(target <= arr[mid][col-1])
            {
                get_row = mid;
                end = mid-1;
            }
            else
            {
                start=mid+1;
            }
            if(prev_mid == mid)
                break;
            prev_mid = mid;
        }
        
        if(get_row!=-1)
        {
            for(int i=0;i<col;i++)
            {
                if(arr[get_row][i]==target)
                    return true;
            }
        }
    
        return false;
    }
};