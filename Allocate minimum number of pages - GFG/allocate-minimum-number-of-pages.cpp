// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    bool IsPossible(int arr[],int n,int s,int mid)
    {
        int sum=0,cnt = 1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>mid)
                return false;
            if(sum+arr[i] > mid)
            {
                cnt++;
                sum = arr[i];
            }
            else
            {
                sum += arr[i];
            }
        }
        if(cnt>s)
            return false;
        return true;
        // int stud = 1, sum=0;
        // for(int i=0;i<n;i++)
        // {
        //     if(arr[i]>mid)
        //         return false;
        //     if(sum+arr[i]>mid)
        //     {
        //         stud++;
        //         sum=0;
        //     }
        //     sum += arr[i];
        // }
        // if(stud>students)
        //     return true;
        // return false;
    }
    
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int students) 
    {
        // sort(arr,arr+n);
        int low = arr[0], high = 0, prev_mid=-1,mid=0;
        for(int i=0;i<n;i++)
            high += arr[i];
        int ans = -1;
        
        while(low<=high)
        {
            mid = (high+low)/2;
            if(IsPossible(arr,n,students,mid))
            {
                // cout<<" -- ";
                high = mid - 1;
                ans = mid;
            }
            else
            {
                low = mid + 1;
            }
            
            // cout<<"mid : "<<mid<<"   high : "<<high<<"   low : "<<low<<endl;
            if(prev_mid==mid)
                break;
            prev_mid=mid;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends