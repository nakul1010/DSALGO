class Solution {
public:
    int singleNumber(vector<int>& arr) 
    {
        int n = arr.size();
        int xor_sum = 0;
        for(int i=0;i<n;i++)
            xor_sum = xor_sum ^ arr[i];
        return xor_sum;
    }
    
};