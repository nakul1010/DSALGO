// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int subseq(int arr[],int n,int k,int product,int &cnt)
    {
        
    	if(product>k)
    	    return 0;
        if(n<0)
        {
            // cnt++;
            return 1;   
        }
        
    	return subseq(arr,n-1,k,product*arr[n],cnt) + subseq(arr,n-1,k,product,cnt);
    	
    }

    int numOfSubsets(int arr[], int n, int k) 
    {
        int cnt=0,product=1;
        return subseq(arr,n-1,k,product,cnt)-1;//IMP__IMP__IMP__IMP__IMP__IMP__IMP__IMP__
        // return cnt-1;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>K;

        Solution ob;
        cout << ob.numOfSubsets(arr,N,K) << endl;
    }
    return 0;
}  // } Driver Code Ends