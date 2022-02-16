class Solution {
public:
    int mySqrt(int x) 
    {
        if(x<=1)
            return x;
        long long start = 0, end = x-1, ans = 0, prev_mid=-1;
        while(start<=end)
        {
            long long mid = (start+end)/2;
            if((mid*mid)==x)
                return mid;
            if((mid*mid) < x)
                ans = mid, start = mid + 1;
            else
                end = mid - 1;
            if(mid == prev_mid)
                break;
            prev_mid = mid;
        }
        return ans;
    }
};