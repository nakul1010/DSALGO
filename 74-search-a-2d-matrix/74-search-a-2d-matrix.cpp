class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) 
    {
        int row = arr.size(), col = arr[0].size();
        
        int get_row = -1;
        for(int i=0;i<row;i++)
        {
            if(target <= arr[i][col-1])
            {
                get_row = i;
                break;
            }
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