// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int kthDiff(int a[], int n, int k);

// Driver code
int main() {
    int t, i;
    int k;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;

        cout << kthDiff(a, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends

int count(int arr[], int n, int mid)
{
    int no = 0;
    for(int i=0;i<n-1;i++)
    {
                    //   start  end  comparison
        no += upper_bound(arr+i,arr+n, arr[i]+mid) - (arr+i+1);
    }
    return no;
}

int kthDiff(int arr[], int n, int k)
{
    if(n==1)
        return 0;
        
    int min_diff = INT_MAX, max_diff = INT_MIN;
    sort(arr,arr+n);
    
    for(int i=0;i<n-1;i++) min_diff = min(min_diff, abs(arr[i+1]-arr[i]));
    
    max_diff = arr[n-1]-arr[0];
    
    int low = min_diff, high = max_diff;
    
    while(low<high)
    {
        int mid = (low+high)>>1;// divide by 2
        if(count(arr,n,mid)<k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}
