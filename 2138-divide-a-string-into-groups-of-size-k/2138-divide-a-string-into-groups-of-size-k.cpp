class Solution {
public:
    vector<string>ans;
    vector<string> divideString(string str, int k, char fill) 
    {
        string curr_str = "";
        
        for(int i=0;i<str.size();i++)
        {
            curr_str += str[i];
            if(curr_str.size()==k)
            {
                ans.push_back(curr_str);
                curr_str = "";
            }
        }
        if(curr_str.size()==0)
            return ans;
        while(curr_str.size()!=k)
        {
            curr_str += fill;
        }
        ans.push_back(curr_str);
        return ans;
    }
};