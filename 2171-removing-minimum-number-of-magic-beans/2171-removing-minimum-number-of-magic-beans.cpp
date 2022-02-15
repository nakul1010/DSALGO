class Solution {
public:
    long long minimumRemoval(vector<int>& arr) 
    {
        vector<int>beans;
        beans =arr;
        sort(beans.begin(), beans.end());
        long long sum = 0;
        for(auto b : beans) sum += b; // total number of beans
        
        long long minrem = LLONG_MAX; //maximum possible value in long long
        for(int i = 0; i < beans.size(); i++)
        {
            long long temp = sum;
            temp -= (beans.size() - i)*beans[i];
            if(minrem > temp) minrem = temp;
        }
        return minrem;
        
//         int n = arr.size();
//         sort(arr.begin(),arr.end());
//         if(n==1)
//             return 0;
//         long long int ans = -1,curr=0,sum=0;
        
//         vector<long long>suffix(n,0);
//         vector<long long>prefix(n,0);
        
//         for(int i=0;i<n;i++)
//         {
//             curr += arr[i];
//             prefix[i] = curr;
//         }
        
        
//         for(int i=n-1;i>=0;i--)
//         {
//             sum += arr[i];
//             if(i!=0)
//                 curr = prefix[i-1] + (sum - ((n-i)*arr[i]));
//             else
//                 curr = sum - ((n-i)*arr[i]);
//             // cout<<"i : "<<i<<"  curr : "<<curr<<endl;
//             if(ans==-1)
//                 ans = curr;
//             else if(curr<ans)
//                 ans=curr;
//         }
//         return ans;
    }
};