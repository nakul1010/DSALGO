// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<string> findMatchedWords(vector<string> dict,string pattern);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> s(n);
		for(int i=0;i<n;i++)
		    cin>>s[i];
		
		string tt;
		cin>>tt;
		
		vector<string> res = findMatchedWords(s,tt);
        sort(res.begin(),res.end());
		for(int i=0;i<res.size();i++)
		    cout<<res[i]<<" ";
		cout<<endl;
		
	}
}// } Driver Code Ends


string get_hash(string str,int n)
{
    string hash = "";
    int x = 0;
    map<char,int>mp;
    for(int i=0;i<n;i++)
    {
        if(mp.find(str[i])!=mp.end())
        {
            hash = hash + to_string(mp[str[i]]);
        }
        else
        {
            hash = hash + to_string(x);
            mp.insert({str[i],x});
            x++;
        }
    }
    
    return hash;
}

vector<string> findMatchedWords(vector<string> dict,string pattern)
{
    vector<string>ans;

    string hash = get_hash(pattern,pattern.length());
    
    int n = dict.size();
    
    for(int i=0;i<n;i++)
    {
        string curr_hash = get_hash(dict[i],dict[i].length());
        if(curr_hash == hash)
            ans.push_back(dict[i]);
    }
    return ans;
}