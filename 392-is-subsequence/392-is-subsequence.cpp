class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        if(t.size()<s.size())    
            return false;
        if(t.size()==s.size())
        {
            if(t==s)
                return true;
            return false;
        }
        
        int n1 = s.size(), n2 = t.size();
        int i=0, j=0;
        
        while(i<n1)
        {
            while(j<n2 && t[j]!=s[i])
            {
                j++;
            }
            if(t[j]!=s[i])
                return false;
            i++,j++;
        }
        return true;
    }
};