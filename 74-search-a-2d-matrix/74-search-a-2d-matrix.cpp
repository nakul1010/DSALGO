class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) 
    {
        int row = arr.size(), col = arr[0].size();
        
        int get_row = -1, start = 0, end = row-1, prev_mid=-1,mid;
        
        while(start<=end)
        {
            mid = (start+end)/2;
            
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
            // cout<<"get_row : "<<get_row<<endl;
            start = 0, end = col-1, prev_mid=-1;//imp to set prev_mid again since change above
            while(start<=end)
            {
                mid = (start+end)/2;
                // cout<<"start : "<<start<<"    end : "<<end<<"    mid : "<<mid<<"     ele : "<<arr[get_row][mid]<<endl;
                if(target == arr[get_row][mid])
                    return true;
                if(arr[get_row][mid] > target)
                {
                    end = mid-1;
                }
                else
                {
                    start = mid+1;
                }
                
                if(prev_mid == mid)
                    break;
                prev_mid = mid;
            }
        }
    
        return false;
    }
};