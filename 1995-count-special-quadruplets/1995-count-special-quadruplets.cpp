class Solution {
public:
    int countQuadruplets(vector<int>& arr) 
    {
        int n = arr.size();
        unordered_set<string>s;
        // sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    for(int l=k+1;l<n;l++)
                    {
                        if(arr[i]+arr[j]+arr[k] == arr[l])
                        {
                            string str =  to_string(i) + " + " + to_string(j) + " + " + to_string(k) + " = " + to_string(l); 
                            // cout<<arr[i]<<" + "<<arr[j]<<" + "<<arr[k]<<" = "<<arr[l]<<endl;
                            // cout<<str<<endl;
                            s.insert(str);
                        }
                    }
                }
            }
        }
        return s.size();
    }
};