class Solution {
public:
    int maxArea(vector<int>& arr) 
    {
        int n = arr.size();
        int max_area = 0;
        int left = 0, right = n-1;
        
        while(left < right)
        {
            int area = min(arr[left],arr[right]) * abs(left-right);
            max_area = max(max_area,area);
            
            if(arr[left] > arr[right])
                right--;
            else 
                left++;
        }
        
        
        return max_area;
    }
};