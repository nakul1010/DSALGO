class Solution {
public:
    string removeKdigits(string str, int k) 
    {
        string ans = "";
        int n = str.size() , i =0;   
        stack<char>s;
        
        while(i<n)
        {
            while(s.empty()==false && k!=0 && str[i]<s.top())
                s.pop(), k--;
            
            s.push(str[i]);
            i++;
        }
        
        while(s.empty()==false && k!=0)//112 k=1
            s.pop(), k--;

        while(s.empty()==false)
        {
            ans = s.top() + ans;
            s.pop();
        }
        cout<<"ans : "<<ans<<endl;
        while(k!=0 && ans.size()>=1)
        {
            ans.erase(0,1);
            k--;
        }
        
        while(ans.size()>=1 && ans[0]=='0')
            ans.erase(0,1);
    
        if(ans.size()==0)
            ans = "0";
        return ans;
    }
};