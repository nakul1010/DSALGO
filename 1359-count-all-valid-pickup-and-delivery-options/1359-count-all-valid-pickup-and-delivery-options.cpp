class Solution {
public:
    int countOrders(int n) 
    {
        long res = 1, mod = 1000000007;
        
        for(int i=1; i<=n ;i++)
        {
            res *= i;//n!
            res %= mod;
            
            res *= (2*i - 1);//2n-1 places 
            res %= mod;
        }
        return res %= mod;
    }
};