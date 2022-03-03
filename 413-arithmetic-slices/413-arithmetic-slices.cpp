class Solution 
{
public:
    int numberOfArithmeticSlices(vector<int>& arr) 
    {
        int n = arr.size();
        if(n<=2)
            return 0;
        int cnt =0 , diff = arr[1]-arr[0], curr_diff , curr_cnt=1;
        
        
        for(int i=1;i<n-1;i++)
        {
            curr_diff = arr[i+1]-arr[i];
            if(curr_diff == diff)
            {
                curr_cnt++;       
            }
            else
            {
                diff = curr_diff;
                if(curr_cnt>=2)
                {
                    int nth = curr_cnt-1;
                    cnt += ((nth * (nth+1))/2)    ;
                }
                curr_cnt = 1;
            }
        }
        if(curr_cnt>=2)
        {
            int nth = curr_cnt-1;
            cnt += ((nth * (nth+1))/2)    ;
        }
        return cnt;
    }
};