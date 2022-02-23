// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) 
    {
        long long s=0,e=n,mid=0,prev_mid=-1;
        while(s<=e)
        {
            mid = (s+e)/2;
            
            if(isBadVersion(mid)==false)
                s = mid+1;
            else 
                e = mid-1;
            
            if(prev_mid == mid)
                break;
            prev_mid  = mid;
        }
        return s;
    }
};